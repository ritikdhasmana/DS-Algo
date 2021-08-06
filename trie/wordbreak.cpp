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
    bool wordBreak(string s,Trie * root){
        int sz=s.length();
        if(sz==0)return true;
        for(int i=1;i<=sz;i++)
        {
            if(root->search(root,s.substr(0,i))&&root->wordBreak(s.substr(i,sz-i),root))
            return true;
        }
        return false;
    }

};




int main() {
    int T=1;
    // cin >> T;
    while (T--) {
        string dictionary[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
   Trie *root = new Trie();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        root->insert(root, dictionary[i]);
  
    root->wordBreak("ilikesamsung", root)? cout <<"Yes\n": cout << "No\n";
    root->wordBreak("iiiiiiii", root)? cout <<"Yes\n": cout << "No\n";
    root->wordBreak("", root)? cout <<"Yes\n": cout << "No\n";
    root->wordBreak("ilikelikeimangoiii", root)? cout <<"Yes\n": cout << "No\n";
    root->wordBreak("samsungandmango", root)? cout <<"Yes\n": cout << "No\n";
    root->wordBreak("samsungandmangok", root)? cout <<"Yes\n": cout << "No\n";
    return 0;
 
 
    }
    
    return 0;
}  // } Driver Code Ends