// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int x = str.length();
		    int y=x;
		    string s1=str, s2=str;
		    
		    int dp[x+1][y+1];
            for(int i=0;i<=x;i++){
                for(int j=0;j<=y;j++)if(i==0||j==0)dp[i][j]=0;
             }
        for(int i=1;i<x+1;i++){
            for(int j=1;j<=y;j++){
                if(i!=j&&s1[i-1]==s2[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                }else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends