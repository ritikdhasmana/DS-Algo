// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long mod = 1e9 + 7;
//   long long dp[1003];
    long long findht(int h){
        if(h==0) return 1;
        if(h==1) return 1;
        long long int a =   findht(h-1)%mod ;
        long long int b =   findht(h-2)%mod ;

        return ((a%mod)*((2*b)%mod + a%mod))%mod;
    }
    long long int countBT(int h) { 
        // code here
        long long int dp[h+1];
        dp[0]=1;
        dp[1]=1;
        for(long long int i=2;i<h+1;i++){
            dp[i] = (dp[i-1]*((2*dp[i-2])%mod + dp[i-1]%mod))%mod;
        }
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends