// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:

    bool isInterleave(string A, string B, string C) 
    {
     
        bool t[A.length()+1][B.length()+1];
        memset(t,0,sizeof(t));
        if(C.length()!=(A.length()+B.length()))return false;
        t[0][0]=1;
        for(int i=0;i<A.length()+1;i++){
            for(int j=0;j<=B.length();j++){
                if(i==0&&j==0)t[i][j]=1;
                else if(i==0){
                    if(B[j-1]==C[j-1])t[i][j] = t[i][j-1];
                }else if(j==0){
                    if(A[i-1]==C[i-1])t[i][j] = t[i-1][j];
                }else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]){
                    t[i][j] = t[i][j-1];
                }else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]){
                    t[i][j] = t[i-1][j];
                }else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]){
                    t[i][j] = t[i][j-1] + t[i-1][j];
                }
            }
        }
        return t[A.length()][B.length()];
        //Your code here
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends