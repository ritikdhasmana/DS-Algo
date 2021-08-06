// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	vector<int> low,tin,parent;

    int timer=0;
	void dfs(int u,vector<int>adj[],vector<pair<int,int>>& bridge)
{
	// static int time = 0;
	tin[u] = low[u] = timer;
	timer+=1;

	for(int v: adj[u])
	{
		if(tin[v]==-1)	//If v is not visited
		{
			parent[v] = u;
			dfs(v,adj,bridge);
			low[u] = min(low[u],low[v]);

			if(low[v] > tin[u])
				bridge.push_back({u,v});
		}
		else if(v!=parent[u])	//Ignore child to parent edge
			low[u] = min(low[u],tin[v]);
	}
}
	void tarjan(int n,vector<int>adj[]){
        vector<bool>vis(n+1,false);
        tin.resize(n,-1);
        low.resize(n,-1);
        cout<<"a"<<endl;
        parent.resize(n,-1);
        vector<pair<int,int>>bridges;
        dfs(0,adj,bridges);
        for (int i = 0; i < bridges.size(); i++)
        {
            cout<<bridges[i].first<<" -> "<<bridges[i].second<<endl;
        }
        
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
            adj[v].push_back(u);
    	}

    	Solution obj;
    	obj.tarjan(V, adj);
    }

    return 0;
}

  // } Driver Code Ends