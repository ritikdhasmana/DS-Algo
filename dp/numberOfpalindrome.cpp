// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long mod= 1e9 +7;
    
    // long long int count(string s, int i, int j){
    //     if(i>j)return 0;
    //     if(i==j)return 1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==s[j]){
    //         return dp[i][j] =  (1 + count(s,i,j-1)%mod + count(s,i+1,j)%mod)%mod;
    //     }
    //     return dp[i][j] = (count(s,i+1,j) + count(s,i,j-1) - count(s,i+1,j-1))%mod;
        
    // }
    
    long long int  countPS(string s)
    {
       //Your code here
       int n = s.length();
       long long dp[n+1][n+1];
       for(long long int g=0;g<n;g++){
           for(long long int i=0,j=g;j<n;i++,j++){
               if(g==0){
                   dp[i][j]=1;
               }
               else if(g==1){
                   if(s[i]==s[j])
                   {
                       dp[i][j]= 3;
                   }
                   else{
                       dp[i][j]= 2;
                   }
               }
               else{
                   if(s[i]==s[j])
                   {
                       dp[i][j]= (1 + (dp[i+1][j]%mod + dp[i][j-1]%mod)%mod)%mod;
                   }
                   else{
                       dp[i][j]= ((dp[i+1][j]%mod + dp[i][j-1]%mod)%mod - dp[i+1][j-1]%mod)%mod;
                   }
                   if(dp[i][j]<0)dp[i][j]+=mod;
               }
           }
       }
       return dp[0][n-1];
       
    }
       
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Endss