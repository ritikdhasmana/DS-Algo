// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings
map<string,int>mp;
int f=0;
map<string,int> dp;
int wordBreak(string a, vector<string> &B) {
    //code here
    if(f==0){
        for(int i=0;i<B.size();i++){
        mp[B[i]]=1;
        }
    f=1;
    }
    if(dp.count(a))return dp[a];
    for( auto w : B){
        string x = a.substr(0,w.length());
        if(x==w){
            if(x.length()==a.length())return dp[a] = 1;
            else{
                if(wordBreak(a.substr(w.length(),a.length()),B)) return dp[a] = 1;
            }
        }
    }
    return dp[a] = 0;
}