// { Driver Code Starts



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution 
{
    public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void Sum(vector<int> &a, int sum,vector<int>&comb,vector<vector<int>>&ans,int i)
    {
        if(sum==0)
        {
            ans.push_back(comb);
            return ;
        }
        while(i<a.size()&&sum-a[i]>=0)
        {
            comb.push_back(a[i]);
            Sum(a,sum-a[i],comb,ans,i);
            i++;
            comb.pop_back();
        }
        //return ans;
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>>v;
        vector<int>a;
        Sum(A,B,a,v,0);
        return v;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends