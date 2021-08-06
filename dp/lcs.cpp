// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    // int dp[1003][1003],f=0;
    // int findlcs(int x, int y, string s1, string s2)
    // {
    //     // your code here
    //     if(f==0){
    //         f=1;
    //         for(int i=0;i<1003;i++){
    //             for(int j=0;j<1003;j++)dp[i][j]=-1;
    //         }
    //     }
    //     if(x==0||y==0)return 0;
    //     if(dp[x][y]!=-1)return dp[x][y];
    //     if(s1[x-1]==s2[y-1]) return dp[x][y] = 1 + lcs(x-1,y-1,s1,s2);
        
    //     return dp[x][y] = max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2)); 
    // }
    
    int lcs2(string &X, string &Y) //space optimized
{
     
    // Find lengths of two strings
    int m = X.length(), n = Y.length();
 
    int L[2][n + 1];
 
    // Binary index, used to
    // index current row and
    // previous row.
    bool bi;
 
    for (int i = 0; i <= m; i++)
    {
         
        // Compute current
        // binary index
        bi = i & 1;
 
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;
 
            else if (X[i-1] == Y[j-1])
                 L[bi][j] = L[1 - bi][j - 1] + 1;
 
            else
                L[bi][j] = max(L[1 - bi][j],
                               L[bi][j - 1]);
        }
    }
 
    // Last filled entry contains
    // length of LCS
    // for X[0..n-1] and Y[0..m-1]
    return L[bi][n];
}

    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[x+1][y+1];
            for(int i=0;i<=x;i++){
                for(int j=0;j<=y;j++)if(i==0||j==0)dp[i][j]=0;
            }
        for(int i=1;i<x+1;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                }else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends