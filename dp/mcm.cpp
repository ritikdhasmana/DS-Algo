// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length. L =2 means AB  BC CD ..... 3 = ABC BCD CDE and so on
    for (L = 2; L < n; L++) 
    {
        for (i = 1; i < n - L + 1; i++) 
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) 
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}






// int dp[105][105];
//     int multrec(int p[], int i, int j){
//     if (i >= j)
//         return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int k;
//     int min = INT_MAX;
//     int count;
//     for (k = i; k < j; k++) 
//     {
//         count = multrec(p, i, k)
//                 + multrec(p, k + 1, j)
//                 + p[i - 1] * p[k] * p[j];

//         if (count < min)
//             min = count;
//     }
//     return dp[i][j]=min;
    
// }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // for(int i=0;i<105;i++)
        // {
        //     for(int j=0;j<105;j++)dp[i][j]=-1;
        // }
        // return multrec(arr,1,N-1);
        return MatrixChainOrder(arr,N);
       
    
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends