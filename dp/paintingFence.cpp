// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long mod= 1e9 + 7;
    long long countWays(int n, int k){
        // code herdp[n+1]={0};
        long long int same=0,ans=0;
        long long int diff = k;
        for(int i=1;i<=n;i++){
            ans= (same%mod + diff%mod)%mod;
            same= diff;
            diff= (ans*(k-1)%mod)%mod;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends