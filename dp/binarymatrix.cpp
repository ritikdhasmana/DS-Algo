// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mini(int a,int b, int c){
    return min(min(a,b),c);
}
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
            {
                if(i==0||j==0)dp[i][j] = 0;
                else if(i==1)dp[i][j] = mat[i-1][j-1];
                else if(j==1)dp[i][j] = mat[i-1][j-1];
            }
        }
        for(int i=2;i<n+1;i++){
            for(int j=2;j<m+1;j++)
            {
                if(mat[i-1][j-1]){
                    dp[i][j]= 1 + mini(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
                }else{
                    dp[i][j]= 0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
            {
                if(dp[i][j]>ans)ans=dp[i][j];
            }
        }
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends