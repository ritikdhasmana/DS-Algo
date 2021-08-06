// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
    if (root1 == NULL || root2 == NULL)
        return 0;
    stack<Node*> st1, st2;
    Node* top1, *top2;
 
    int count = 0;
    while (1) {
        while (root1 != NULL) {
            st1.push(root1);
            root1 = root1->left;
        }
        while (root2 != NULL) {
            st2.push(root2);
            root2 = root2->right;
        }
        if (st1.empty() || st2.empty())
            break;
 
        top1 = st1.top();
        top2 = st2.top();
        if ((top1->data + top2->data) == x) {
  
            count++;
            st1.pop();
            st2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }
        else if ((top1->data + top2->data) < x) {
            st1.pop();
            root1 = top1->right;
        }
        else {
            st2.pop();
            root2 = top2->left;
        }
    }
    return count;
}
