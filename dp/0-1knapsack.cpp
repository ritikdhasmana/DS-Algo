// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    int sz;
    
    //Function to return max value that can be put in knapsack of capacity W.
    // int maxval(int wt[],int val[],int curwt,int ind){
       
    //   if(curwt==0||ind==-1)return 0;
    //   if(dp[ind][curwt]!=-1)return dp[ind][curwt];
    //   if(curwt>=wt[ind]){
    //       return dp[ind][curwt]=max(maxval(wt,val,curwt,ind-1),val[ind]+maxval(wt,val,curwt-wt[ind],ind-1));
    //   }
    //   return dp[ind][curwt]=maxval(wt,val,curwt,ind-1);
    // }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       sz=n;
       int dp[n+1][w+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)if(i==0||j==0)dp[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(j>=wt[i-1]){
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends