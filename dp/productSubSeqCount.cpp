// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int productcount(int a[],int n,int k)
    {
        int dp[k + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<k+1;j++){
                if(i==0||j==0)dp[i][j]=0;
            }
        }
        for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (a[j - 1] <= i && a[j - 1] > 0)
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/a[j-1]][j-1] + 1;
        }
    }
        return dp[k][n];
    }
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.productcount(a, n,k) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends