// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long >st;
       if(n==1)return arr[0];
        long long ans=0,i=0;
        while(i<n){
            if(!st.size()||arr[st.top()]<=arr[i])st.push(i++);
            else{
                int x=st.top();
                st.pop();
                long long area= arr[x]*(i-(st.size()?st.top()+1:0));
                ans=max(area,ans);
            }
        }
        while(st.size()){
                int x=st.top();
                st.pop();
                // cout<<x<<" " <<arr[x]<<"  "<<ans<<endl;
                long long area= arr[x]*((n)-(st.size()?(st.top()+1):0));
                ans=max(area,ans);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends