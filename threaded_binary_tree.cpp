#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    int last_data;
    Node *insertNode(Node *root, int key);
    void lastNode(Node *root);

    void inordersucc(Node *root);
};

Node *BST::insertNode(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data == -1)
    {
        root->data = key;
        return root;
    }
    if (key < root->data)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);
    return root;
}

void BST::lastNode(Node *root)
{
    if (root == NULL)
        return;
    last_data = root->data;
    lastNode(root->right);
}

void BST::inordersucc(Node *root)
{
    if (root == NULL)
        return;
    inordersucc(root->left);
    if (root->right == NULL && root->data != last_data)
    {
        cout << root->data << "->"
             << "true" << endl;
    }
    inordersucc(root->right);
}

int main()
{

    Node *root = new Node(-1);
    BST obj;
    int n;
    cout << "How many elements you want to enter in BST: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter element: ";
        cin >> data;
        obj.insertNode(root, data);
    }

    obj.lastNode(root);
    cout <<endl<<endl<<"Threaded Roots are: " << endl
         << endl;
    obj.inordersucc(root);

    return 0;
}