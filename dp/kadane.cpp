// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // important-----------------------------------------------------------
    int smallestSumSubarr(int arr[], int n)
{
    // to store the minimum value that is ending
    // up to the current index
    int min_ending_here = INT_MAX;
     
    // to store the minimum value encountered so far
    int min_so_far = INT_MAX;
     
    // traverse the array elements
    for (int i=0; i<n; i++)
    {
        // if min_ending_here > 0, then it could not possibly
        // contribute to the minimum sum further
        if (min_ending_here > 0)
            min_ending_here = arr[i];
         
        // else add the value arr[i] to min_ending_here   
        else
            min_ending_here += arr[i];
         
        // update min_so_far
        min_so_far = min(min_so_far, min_ending_here);           
    }
     
    // required smallest sum contiguous subarray value
    return min_so_far;
}

    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int x = *max_element(arr,arr+n);
        if(x<0)return *min_element(arr,arr + n);
         int ans=0;
         int cursum=0;
         for(int i=0;i<n;i++){
             if(cursum+arr[i] > 0){
                 cursum+=arr[i];
             }else cursum=0;
             ans= max(ans,cursum);
         }
         
         return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends