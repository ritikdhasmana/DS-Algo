// implement trie.......

#include <bits/stdc++.h>
using namespace std;



class Trie
{
    char data;
    bool endofword;
    Trie * child[26];
	public:
    Trie()
    {
        this->endofword = false;
 
        for (int i = 0; i < 26; i++) {
            this->child[i] = nullptr;
        }
    }

    Trie *getNode(char c){
        Trie * node = new Trie;
        node->endofword=false;
        node->data = c;
        for (int i = 0; i < 26; i++)
        {
            node->child[i]=NULL;
        }
        return node;
    }
    void insert(Trie * root , string s)
    {
        Trie * p= root;
        int n=s.length();
        for (int i = 0; i < n; i++)
        {
            int k= s[i]-'a';
            if(!p->child[k]){
                p->child[k]= getNode(s[i]);
            }
            p=p->child[k];
        }
        p->endofword=true;
        
    }
    bool search(Trie * root , string s)
    {
        Trie *p=root;
        int n= s.length();
        for (int i = 0; i < n; i++)
        {
            int k=s[i]-'a';
            if(p->child[k]==NULL)return false;
            p=p->child[k];
        }
        return (p&&p->endofword);
        
    }
    bool deletion(Trie * root,string s)
    {
        if(root==nullptr)return false;
        if(search(root,s)){
            Trie * cur=root;
            int ind;
            for (int i = 0; i<s.length(); i++)
            {
                ind= s[i]-'a';
                if(cur->child[ind]==NULL)return false;
                cur= cur->child[ind];
            }
            cur->endofword=false;
            return true;
        }
        return false;
    }

};




int main() {
    int T=1;
    // cin >> T;
    while (T--) {
        Trie* head = new Trie();
 
    head->insert(head,"hello");
    cout << head->search(head,"hello") << " ";      // print 1
 
    head->insert(head,"helloworld");
    cout << head->search(head,"helloworld") << " "; // print 1
 
    cout << head->search(head,"helll") << " ";      // print 0 (Not found)
 
    head->insert(head,"hell");
    cout << head->search(head,"hell") << " ";       // print 1
 
    head->insert(head,"h");
    cout << head->search(head,"h");                 // print 1
 
    cout << endl;
 
    head->deletion(head, "hello");
    cout << head->search(head,"hello") << " ";      // print 0
 
    cout << head->search(head,"helloworld") << " "; // print 1
    cout << head->search(head,"hell");              // print 1
 
    cout << endl;
 
    head->deletion(head, "h");
    cout << head->search(head,"h") << " ";          // print 0
    cout << head->search(head,"hell") << " ";       // print 1
    cout << head->search(head,"helloworld");        // print 1
 
    cout << endl;
 
    head->deletion(head, "helloworld");
    cout << head->search(head,"helloworld") << " "; // print 0
    cout << head->search(head,"hell") << " ";       // print 1
 
    head->deletion(head, "hell");
    cout << head->search(head,"hell");              // print 0
 
    cout << endl;
 
    if (head == nullptr) {
        cout << "Trie empty!!\n";              // Trie is empty now
    }
 
    cout << head->search(head,"hell");              // print 0
        
    }
    
    return 0;
}  // } Driver Code Ends