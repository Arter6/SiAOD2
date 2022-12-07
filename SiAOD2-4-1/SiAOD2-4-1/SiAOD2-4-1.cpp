#include <iostream>
#include <stack>
#include <queue>
using namespace std;

string space = " "; // Переменная, используемая в дальнейшем для вывода элементов на определённом расстоянии
int k = 64; // Работает в паре с предыдущей, зависит от глубины дерева

string operator * (string s, unsigned int n) // Перегрузка оператора умножения для строк. Пример: "abc" * 3 = "abcabcabc"
{
    string ns="";
    while (n)
    {
        ns += s;
        n--;
    }
    return ns;
}

struct node
{
    char oper;
    node* left;
    node* right;

    node(char oper=NULL, node* left=nullptr, node* right=nullptr)
    {
        this->oper = oper;
        this->left = left;
        this->right = right;
    }

    ~node()
    {
        delete left;
        delete right;
    }

    //обратная польская запись
    //expression tree with infix notation

};

bool isExpCorrect(string exp) // Проверка корректности введённого выражения
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (!isdigit(static_cast<unsigned char>(exp[i])) and !(exp[i] == '+' or exp[i] == '-' or exp[i] == '*'))
            return false;
    }
    return true;
}

int precedence(char op) // Приоритет операций
{
    switch (op)
    {
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

string infixToPostfix(string infix) // Перевод из инфиксной (человеческой) нотации в постфиксную
{
    stack<char> st;
    string postfix = "";
    string::iterator it;
    for (it = infix.begin(); it != infix.end(); it++)
    {
        if (isdigit(unsigned char(*it))) postfix += *it;
        else
        {
            if (st.empty() or precedence(*it) > precedence(st.top())) st.push(*it);
            else
            {
                while (!st.empty() and precedence(*it) <= precedence(st.top()))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(*it);
            }
        }
    }
    
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

node* buildTree(node* Tree,string postfix)
{
    stack<node*> st;
    node* temp_tree1;
    node* temp_tree2;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (!(postfix[i] == '+' or postfix[i] == '-' or postfix[i] == '*'))
        {
            Tree = new node(postfix[i]);
            st.push(Tree);
        }
        else
        {
            Tree = new node(postfix[i]);
            temp_tree1 = st.top();
            st.pop();
            temp_tree2 = st.top();
            st.pop();
            Tree->left = temp_tree2;
            Tree->right = temp_tree1;
            st.push(Tree);
        }
    }
    return Tree;
}

void print2DUtil(node* root, int delim)
{
    if (root == NULL)
        return;

    delim += 10;

    print2DUtil(root->right, delim);

    cout << endl <<endl<< space * (delim+5) << root->oper << "\n";
    print2DUtil(root->left, delim);
}

void print2D(node* root)
{
    print2DUtil(root, -10);
}

void printLevelOrder(node* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        node* node = q.front();
        cout << node->oper << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

node* leftMost(node* root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

int eval(node* root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return int(root->oper - '0');

    int l_val = eval(root->left);

    int r_val = eval(root->right);

    // Check which operator to apply
    if (root->oper ==  '+')
        return l_val + r_val;

    if (root->oper == '-')
        return l_val - r_val;

    if (root->oper == '*')
        return l_val * r_val;

    return l_val / r_val;
}

int main()
{
    setlocale(0, "");
    string s = "1*(2+3)*(4-5)";
    cout << isExpCorrect(s)<<endl;
    string ps = infixToPostfix(s);
    cout << "Постфиксная форма: "<<ps << endl;
    cout << "__________________\n";
    node* Tree=new node();
    Tree = buildTree(Tree, ps);
    print2D(Tree);
    cout << "\n__________________\n";
    printLevelOrder(Tree);
    cout << "\n__________________\n";
    //cout << eval(Tree);
    delete Tree;
}