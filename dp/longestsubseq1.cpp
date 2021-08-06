// { Driver Code Starts
// given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        int t[n+1];
        for(int i=0;i<n;i++)t[i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(a[j]-a[i])==1){
                    t[i]=max(t[i],t[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,t[i]);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends