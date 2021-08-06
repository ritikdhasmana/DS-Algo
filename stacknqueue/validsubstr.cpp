// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int o=0,c=0;
         int ans=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')st.push(i);
            else{
                // int x=-1;
                if(st.size()){
                    // x=st.top();
                    st.pop();
                }
                if(st.size()){
                    int ind=st.top();
                    int temp= i-ind;
                    // cout<<ind<<" "<<i<<" "<<temp<<" "<<s[i]<<endl;
                    ans=max(temp,ans);
                }else{
                    st.push(i);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends