// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	long long int s[] = {3,5,10};
	for(int j=0;j<3;j++){
	    for(long long int i=1;i<=n;i++){
	        if(s[j]<=i){
	            if(s[j]==i)table[i]++;
	            else table[i]+=table[i-s[j]];
	        }
	        
	    }
	   
	}
	// Your code here
	
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends