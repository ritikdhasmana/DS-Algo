// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
   
    
    void dfs(int v,vector<int> adj[],vector<int>& ans,vector<bool>vis){
        vis[v]=true;
        ans.push_back(v);
        for(int i : adj[v]){
            if(!vis[i])dfs(i,adj,ans,vis);

        }
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<bool>vis(V+1,false);
        vector<int> ans;
        obj.dfs(0, adj,ans,vis);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends