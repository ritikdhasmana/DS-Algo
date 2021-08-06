// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.
long long tot=0, dp[1003][1003];
long long amount(int i,int j, int arr[])
{
    if(i>=j){
        // if(c>tot)tot=c;
        return 0;
    }
    if(i==j+1)return max(arr[i],arr[j]);
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]  = max(arr[i]+min(amount(i+1,j-1,arr),amount(i+2,j,arr)), arr[j]+min(amount(i+1,j-1,arr),amount(i,j-2,arr)));
}
long long maximumAmount(int arr[], int n) 
{
    for(int i=0;i<1003;i++){
        for(int j=0;j<1003;j++)dp[i][j]=-1;
    }
    return amount(0,n-1,arr);
    // Your code here
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends