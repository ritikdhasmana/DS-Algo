// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxi(int a , int b, int c){return max(max(a,b),c);}
    
    int maxGold(int n, int m, vector<vector<int>> mine)
    {
        // code here
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        // for(int i=1;i<=n;i++){
        //     dp[i][m]=mine[i-1][m-1];
        // }
        for(int col=m-1;col>=0;col--){
            for(int i=0;i<n;i++){
                int ru = (col==m-1||i==0)?0:dp[i-1][col+1];
                int rd= (i==n-1||col==m-1)?0:dp[i+1][col+1];
                int r= (col==m-1)?0:dp[i][col+1];
                dp[i][col]= mine[i][col]+ maxi(rd,ru,r);
            }
        }
        int ans=dp[0][0];
        for(int i=1;i<n;i++)ans= max(ans,dp[i][0]);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends