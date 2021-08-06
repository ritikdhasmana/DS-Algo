// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int x=n/2;

        //can use stack instead of two pointer to find potential candidate...............just push all and then pop two and compare em
        int i=0,j=n-1;
        while(i<j){
            if(M[i][j]==1)i++;
            else j--;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=j&&(!M[i][j]||M[j][i]))return -1;
        }
         return j;
    }
   
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends