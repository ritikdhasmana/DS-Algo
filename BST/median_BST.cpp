// { Driver Code Starts
// C++ implementation to find median using morris traversal 
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

int count(Node * root)
{
    int cnt=0;
    Node *cur=root,*predecessor=nullptr;
    while(cur)
    {
        if(!cur->left)
        {
            cnt++;
            cur=cur->right;
        }
        else{
            predecessor=cur->left;
            while(predecessor && predecessor->right&&predecessor->right!=cur)predecessor=predecessor->right;
            if(predecessor->right==NULL)
            {
                predecessor->right=cur;
                cur=cur->left;
            }else{
                predecessor->right=NULL;
                cnt++;
                cur=cur->right;
            }
        }
    }
    return cnt;
}
int median(Node *root)
{
    if(!root)return 0;
    int nodecount=count(root),ans=-1,cnt=0;
    Node * cur=root,*prev=NULL,*p=NULL;
    while(cur)
    {
        if(!cur->left)
        {
            cnt++;
            if(nodecount%2!=0&&cnt==(nodecount+1)/2)return cur->data;
            else if(nodecount%2==0&&cnt==(nodecount+1)/2)return (cur->data+prev->data)/2;
            prev=cur;
            cur=cur->right;
        }
        else{
            p=cur->left;
            while(p && p->right&&p->right!=cur)p=p->right;
            if(p->right==NULL)
            {
                p->right=cur;
                prev=cur;
                cur=cur->left;
            }else{
                p->right=NULL;
                prev=p;
                cnt++;
                if(nodecount%2!=0&&cnt==(nodecount+1)/2)return cur->data;
                else if(nodecount%2==0&&cnt==(nodecount+1)/2)return (cur->data+prev->data)/2;
                prev=cur;
                cur=cur->right;
            }
        }
    }
    return ans;
}

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
        
        cout<<median(root1)<<"\n";
    }
    return 0;
}


