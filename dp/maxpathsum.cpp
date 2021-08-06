// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> m)
    {
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>0 && j<n-1){
                    m[i][j]+= max( max(m[i-1][j],m[i-1][j-1]),m[i-1][j+1]);
                }else if(j==0){
                    m[i][j]+= max(m[i-1][j],m[i-1][j+1]);
                }else{
                    m[i][j]+= max(m[i-1][j],m[i-1][j-1]);
                }
            }
        }    
        int ans=0;
        for(int i=0;i<n;i++){
            ans= max( ans, m[n-1][i]);
        }
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends