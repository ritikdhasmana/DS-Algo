// { Driver Code Starts
// Initial Template for C++
// print all the valid words with memoization....
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

unordered_map<string,vector<string>>dp;
class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        if(dp.count(s))return dp[s];
        vector<string>res;
        for(auto w:dict)
        {
            if(s.substr(0,w.length())==w)
            {
                if(w.length()==s.length())
                {
                    res.push_back(w);
                }
                else{
                    vector<string>temp=wordBreak(n,dict,s.substr(w.length()));
                    for(auto t:temp)
                    {
                        res.push_back(w+" "+t);
                    }
                }
            }
        }
        return dp[s]=res;
        // code here

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends