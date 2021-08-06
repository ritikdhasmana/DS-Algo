// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod= 1e9 + 7;
    int dp[1000006];
    int pairs(int  n){
        if(n<0)return 0;
        if (dp[n] != -1)
        return dp[n];
        if(n<=2)return dp[n]= n;
        else{
            return dp[n]= ((pairs(n-1))%mod + (n-1)*pairs(n-2)%mod)%mod;
        }
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        // memset(dp,-1,1000006);
        // return pairs(n);
         long long a = 1, b = 2, c = 0;
         if (n <= 2) {
            return n;
         }
         for (int i = 3; i <= n; i++) {
            c =( b + (((i - 1)%mod * a%mod)%mod)%mod)%mod;
            a = b%mod;
            b = c%mod;
        }
        return c;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends