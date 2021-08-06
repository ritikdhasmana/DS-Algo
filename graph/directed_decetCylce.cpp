// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	vector<bool> vis=vector<bool>(100005,false);
	vector<bool> cur=vector<bool>(100005,false);
	
	bool check(int v, vector<int> adj[]){
	   // if(cur[v])return true;
	    vis[v]=true;
	    cur[v]=true;
	    for(int i : adj[v]){
	        if(cur[i])return true;
	        if(!vis[i]){
	            bool t = check(i,adj);
	           // cout<<i<<t<<v<<endl;
	            if (t)return true;
	        }
	    }
	    cur[v]=false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            bool t = check(i,adj);
	            if(t)return true;
	        }
	    }
	    return false;
	   	// code here
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends