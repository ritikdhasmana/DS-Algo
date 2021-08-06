// kadane...............
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int ans=-1, len=0;
	    // Your code goes here
	    for(int i=0;i<S.length();i++){
	        if(S[i]=='0'){
	            len++;
	            
	        }else{
	            if(len==0)continue;
	            len--;
	            
	        }
	        ans=max(ans,len);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends