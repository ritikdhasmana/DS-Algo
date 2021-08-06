// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  int sz;
//   long long int dp[1005][1005];
//     long long ways(int s[],int cursum,int ind)
//     {
//         if(dp[cursum][ind]!=-1)return dp[cursum][ind];
//         if(cursum==0)return 1;
//         if(ind>=sz)return 0;
//         if(cursum-s[ind]>=0){
//             return dp[cursum][ind]=ways(s,cursum,ind+1)+ways(s,cursum-s[ind],ind );
//         }
//         return dp[cursum][ind]= ways(s,cursum,ind+1);
//     }
    
    long long dpways(int s[],int sum){
        long long dp[sum+1]={0};
        dp[0]=1;
        for(int i=0;i<sz;i++){
            for(int c= s[i];c<sum+1;c++){
                dp[c]+=dp[c-s[i]];
            }
        }
        return dp[sum];
    }
    
    long long int count( int S[], int m, int n )
    {
        sz=m;
        // for(int i=0;i<1005;i++)
        // {
        //     for(int j=0;j<1005;j++)dp[i][j]=-1;
        // }
        return dpways(S,n);
        
        //code here.
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends