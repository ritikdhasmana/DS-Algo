// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int maxi(int a,int b, int c){
    return max(max(a,b),c);
}

int LCSof3 (string a, string b, string c, int x, int y, int z)
{
    int dp[x+1][y+1][z+1];
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                for(int k=0;k<z+1;k++)if(!i||!j||!k)dp[i][j][k]=0;
            }
        }

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            for(int k=1;k<z+1;k++)
            {
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else{
                    dp[i][j][k]= maxi(dp[i][j][k-1],dp[i][j-1][k],dp[i-1][j][k]);
                }
            }
        }
    }
    
    
    return dp[x][y][z] ;
}