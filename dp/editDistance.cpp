// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int rec(string s,string t,int m,int n)
    {
        if(m==0)return n;
        if(n==0)return m;

        if(s[m-1]==s[n-1])return rec(s,t,m-1,n-1);
        
        return 
        1 + min(min(rec(s,t,m-1,n),rec(s,t,m,n-1)),rec(s,t,m-1,n-1));
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length(),m=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<m+1;j++){
                if(i==0)dp[i][j]=j;
                if(j==00)dp[i][j]=i;
            }
        }
       for(int i=1;i<=n;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]!=t[j-1])
                {
                    dp[i][j]=1+ min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }else{
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends