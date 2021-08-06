// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maxi(int a, int b, int c){
        return max(max(a,b),c);
    }
    // int dp[10005] , f=0;
    // int find(int n, int x, int y, int z){
    //     if(n<0)return INT_MIN;
    //     if(n==0)return 0;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n]= 1 + maxi(find(n-x,x,y,z),find(n-y,x,y,z),find(n-z,x,y,z));
        
    // }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
        // for(int i=0;i<=10004;i++)dp[i]=-1;
        // int ans=find(n,x,y,z);
        // return (ans<0)?0:ans;
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int a = (i-x)<0 ? INT_MIN : dp[i-x];
            int b = (i-y)<0 ? INT_MIN : dp[i-y];
            int c = (i-z)<0 ? INT_MIN : dp[i-z];
            dp[i]= 1 + maxi(a,b,c);
        }
        return dp[n]<0? 0: dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends