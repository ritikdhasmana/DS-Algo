// { Driver Code Starts
// all possible paths from top corner to bottom right corner 

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++


const int num=100000;
class Solution{
    public:
    bool safe(int i,int j,vector<vector<int>> &m,int n,bool vis[][num] )
    {
        if(i==-1||j==-1||i==n||j==n)return false;
        if(m[i][j]==0||vis[i][j])return false;
        return true;
    }

    void allpath(int i,int j,vector<vector<int>> &m,int n,string &path,vector<string>&ans,bool vis[][num])
    {
        if(!safe(i,j,m,n,vis))return;
        if(i==n-1&&j==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[i][j]=true;
        if(safe(i+1,j,m,n,vis))
        {
            path+='D';
            allpath(i+1,j,m,n,path,ans,vis);
            path.pop_back();
        }
        if(safe(i,j-1,m,n,vis))
        {
            path+='L';
            allpath(i,j-1,m,n,path,ans,vis);
            path.pop_back();
        }
        if(safe(i,j+1,m,n,vis))
        {
            path+='R';
            allpath(i,j+1,m,n,path,ans,vis);
            path.pop_back();
        }
        if(safe(i-1,j,m,n,vis))
        {
            path+='U';
            allpath(i-1,j,m,n,path,ans,vis);
            path.pop_back();
        }
        
        vis[i][j]=false;
    }    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        // num=n+1;
        string path;
        bool vis[n][num];
        memset(vis,false,sizeof(vis));
        allpath(0,0,m,n,path,ans,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends