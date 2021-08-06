// implement trie.......

#include <bits/stdc++.h>
using namespace std;



class Trie
{
    public:
    char data;
    bool endofword;
    Trie * child[26];
    int freq;
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
        node->freq=0;
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
            p->freq++;
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
    void findprefixuntill(Trie * root,vector<string>& ans,string &s)
    {
        if(root->freq<=1){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<26;i++){
            if(root->child[i]){
                Trie * temp = root->child[i];
                s+=temp->data;
                findprefixuntill(temp,ans,s);
                s.pop_back();
            }
        }
    }
    void findPrefix( Trie * root)
    {
        Trie * cur= root;
        vector<string>ans;
        for(int i=0;i<26;i++)
        {
            if(cur->child[i]){
                Trie * temp = cur->child[i];
                string s="";
                s+=temp->data;
                findprefixuntill( temp, ans,s);
            }
        }

        cout<<"Unique prefixes- "<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<endl;
        }
        
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
    cout << head->search(head,"hellicopter") << " ";       // print 1
 
    head->insert(head,"hii");
    cout << head->search(head,"hii");                 // print 1
    
    head->insert(head,"dog");
    cout << head->search(head,"dog");  

    head->insert(head,"cat");
    cout << head->search(head,"cat");  
    // cout<< head->child['h'-'a']->freq;
    
    cout << endl;
    head->findPrefix(head);
 
 
    }
    
    return 0;
}  // } Driver Code Ends