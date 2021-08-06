// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        sort(arr,arr+n);
        int t[n+1]={0};
        // t[0]=0;
        
        for(int i=1;i<n;i++){
            // cout<<t[i]<<" "<<arr[i]<<" "<<arr[i-1]<<"     ";
            if(arr[i]-arr[i-1] < k){
                // cout<<"yes"<<endl;
                int temp=  (i>1)? t[i-2] : 0;
                t[i] = arr[i] + arr[i-1] + temp;
                
            }else{
                t[i]=t[i-1];
            }
        }
        // for(int i=1;i<n;i++)cout<<t[i]<<" ";
        return t[n-1];
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends