#include <iostream>
using namespace std;
 
class BST
{
    
 
public:
    int data;
    BST *left, *right;
    // Default constructor.
    BST();
 
    // Parameterized constructor.
    BST(int);
 
    // Insert function.
    BST* Insert(BST*, int);
    void Inorder(BST*);
};
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        return new BST(value);
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}
void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

BST* find(BST *root,int key)
{
    if(!root)return NULL ;
    if(root->data==key)return root;
    else if(root->data<key)return find(root->right,key);
    return find(root->left,key);
}

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 5);
    b.Insert(root, 3);
    b.Insert(root, 2);
    b.Insert(root, 4);
    b.Insert(root, 7);
    b.Insert(root, 6);
    b.Insert(root, 8);
    cout<<"Inorder traversal- "<<endl;
    b.Inorder(root);

    BST *temp = find(root,7);
    string s="key found !";
    if(temp==NULL)s="key not found!";
    cout<<s<<endl;
    temp=find(root,8);
    s="key found !";
    if(temp==NULL)s="key not found!";
    cout<<s<<endl;
    temp=find(root,9);
    s="key found !";
    if(temp==NULL)s="key not found!";
    cout<<s<<endl;
    return 0;
}
 