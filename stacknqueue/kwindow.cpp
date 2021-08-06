// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int n, long long int k) {
     
     queue<long long>q;
     vector<long long >ans(n-k+1);
     for(int i=0;i<n;i++)if(A[i]<0)q.push(i);
     for(int i=0;i<n-k+1;i++){
         if(q.empty()){
             ans[i]=0;
             continue;
         }
         int x=q.front();
         if(x>=i&&x<i+k)ans[i]=A[x];
         else ans[i]=0;
         if( x<=i)q.pop();
     }
     return ans;
 }