// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    // int dp[201][201],f=0;
    // int memoize(int n,int k){
    //     if(f==0){
    //         f=1;
    //         for(int i=0;i<201;i++){
    //             for(int j=0;j<201;j++)dp[i][j]=-1;
    //         }
    //     }
    //     if(k==1 || k==0 || n==1)return k;
    //     if(dp[n][k]!=-1)return dp[n][k];
    //     int ans=INT_MAX;
    //     for(int i=1;i<=k;i++){
    //         int t= max(eggDrop(n-1,i-1),eggDrop(n,k-i));
    //         ans= min(ans,t);
    //     }
    //     return dp[n][k] = ans + 1;
    // }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=k;j++){
                if(j==1 || j==0 || i==1)dp[i][j]=j;
            }
        }
        for(int i=2;i<n+1;i++){
            for(int j=2;j<=k;j++){
                int ans=INT_MAX;
                for(int x=1;x<=j;x++){
                    int t = max(dp[i-1][x-1],dp[i][j-x]);
                    ans=min(ans,t);
                }
                dp[i][j]=1+ans;
            }
        }
        return dp[n][k];
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends