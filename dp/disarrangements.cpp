// { Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long mod =1e9 +7;
    long int disarrange(int N){
        // code here
        long long int ans=0, s = 0, f = 1; 
        if(N<=1)return 0;
        if(N==2)return 1;
        for(int i=3;i<=N;i++){
            ans = (i-1)*(s + f)%mod;
            s=f;
            f=ans;
        }
        return ans%mod;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends