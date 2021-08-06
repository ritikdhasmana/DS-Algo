//Maximum subsequence sum such that no three are consecutive

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int subsum(int n, int arr[])
    {
        int s[n];
        s[0]=arr[0];
        for(int i=1;i<n;i++){
            int s1 = s[i-1];
            int s2 = (i>1)? s[i-2] + arr[i] : arr[i];
            int s3 = (i>2)? s[i-3] + arr[i] + arr[i-1] :arr[i] + arr[i-1];
            s[i]= max(max(s1,s2),s3);
        }
        return s[n-1];
       
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
       cout<<(ob.subsum(N, arr))<<endl;
            
    }
    return 0;
}  // } Driver Code Ends