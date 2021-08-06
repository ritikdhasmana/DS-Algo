// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	vector<int> order;
	void dfs(int i,vector<bool>&vis,vector<int>adj[])
	{
	    vis[i]=true;
	    for(int x : adj[i])
	    {
	        if(!vis[x])dfs(x,vis,adj);
	    }
	    order.push_back(i);
	}
	void dfs1(int i,vector<bool>&vis1,vector<int>adj[])
	{
	    vis1[i]=true;
	    for(int x : adj[i])
	    {
	        if(!vis1[x])dfs1(x,vis1,adj);
	    }
	   // order.push_back(i);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        order.clear();//topo
        
        vector<int>rev[v];
        for(int i=0;i<v;i++)
        {
            for(int x : adj[i]){
                rev[x].push_back(i);
            }
        }
        vector<bool> vis(v+1,false),vis1(v+1,false);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])dfs(i,vis,adj);
        }
        int ans=0;
        
        for(int i=order.size()-1;i>=0;i--)
        {
            // cout<<order[i]<<" ab"<<vis1[order[i]]<<" i- ";
            // for(int j=0;j<rev[order[i]].size();j++)cout<<rev[order[i]][j]<<" ";
            // cout<<endl;
            if(!vis1[order[i]]){
                dfs1(order[i],vis1,rev);
                ans++;
            }
        }
        return ans;   
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends