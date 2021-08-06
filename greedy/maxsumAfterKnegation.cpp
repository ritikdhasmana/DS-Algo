// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(!k)break;
            if(a[i]<0)
            {
                a[i]=-a[i];
                k--;
            }
        }
        sort(a,a+n);
        if(k%2!=0)a[0]=-a[0];
        long long int s=0;
        for(int i=0;i<n;i++)
        {
            s+=a[i];
        }
        //cout<<s<<endl;/
        return s;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends