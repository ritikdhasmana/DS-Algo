// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[600][600];
    bool ispal(string s, int i, int n)
    {
        int j =n;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int part(string str,int i , int j) {
        
        if(i>=j)return 0;
        if(ispal(str,i,j))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int x=i;x<j;x++){
            // string s = str.substr(i,x)
            int f,s;
             f= (dp[i][x]!=-1) ? dp[i][x] : (part(str,i,x));
             s= (dp[x+1][j]!=-1) ? dp[x+1][j] : (part(str,x+1,j));
            
            ans = min(ans,1 + f + s);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
       
        for(int i=0;i<600;i++){
            for(int j=0;j<600;j++)dp[i][j]=-1;
        }
        return part(str,0,str.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends