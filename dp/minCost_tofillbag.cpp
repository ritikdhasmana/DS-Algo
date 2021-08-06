// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	int dp[1004][1004];
	int rec(int c[],int n,int w,int curc){
	    if(w==0)return 0;
	    if(n==0)return 1e9;
	    if(dp[n][w]!=-1)return dp[n][w];
	    if(n<=w&&c[n-1]!=-1){
	        return dp[n][w]= min(rec(c,n-1,w,curc),c[n-1]+rec(c,n,w-n,curc));
	    }
	    return dp[n][w]= rec(c,n-1,w,curc);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        for(int i=0;i<1004;i++)
        {
            for(int j=0;j<1004;j++)dp[i][j]=-1;
        }
        int ans=rec(cost,N,W,0);
        return ans==1e9 ? -1 : ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends