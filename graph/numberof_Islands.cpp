// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    void dfs(vector<vector<char>>& m,int i,int j,int r,int c)
    {
        if(i>=r||j>=c||i<0||j<0||m[i][j]!='1')return;

            m[i][j]='0';
            dfs(m,i+1,j,r,c);
            dfs(m,i-1,j,r,c);
            dfs(m,i,j+1,r,c);
            dfs(m,i,j-1,r,c);
            dfs(m,i-1,j-1,r,c);
            dfs(m,i-1,j+1,r,c);
            dfs(m,i+1,j-1,r,c);
            dfs(m,i+1,j+1,r,c);
        
    }


    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int r=grid.size();
        int c= grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            {
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]='0';
                    
                    dfs(grid,i+1,j,r,c);
                    dfs(grid,i-1,j,r,c);
                    dfs(grid,i,j+1,r,c);
                    dfs(grid,i,j-1,r,c);
                    dfs(grid,i+1,j+1,r,c);
                    dfs(grid,i-1,j-1,r,c);
                    dfs(grid,i+1,j-1,r,c);
                    dfs(grid,i-1,j+1,r,c);
                    
                   
                }
            }
        }
	    return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Endss