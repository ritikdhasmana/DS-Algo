// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
int NINF = INT_MIN;


class Solution
{
	public:
    void dfs(int u,vector<pair<int,int>> adj[],vector<bool>& vis,stack<int>& st)
    {
        vis[u]=true;
        for(auto it : adj[u])
        {
            int i= it.first;
            if(!vis[i])dfs(i,adj,vis,st);
        }
        st.push(u);
    }
	void longestpath(int s,int n,vector<pair<int,int>>adj[]){
        vector<int> dis(n,NINF);
        dis[s]=0;
        vector<bool>vis(n,false);
        stack<int> st;
        dfs(0,adj,vis,st);
        while(st.size()){
            int u=st.top();
            st.pop();
            if(dis[u]!=NINF){
                for (auto it : adj[u])
                {
                    int v= it.first;
                    int wt= it.second;
                    if(dis[u]+wt > dis[v])dis[v]=dis[u]+wt;
                }
                
            }
        }
        for(int i=0;i<n;i++){
            (dis[i]==NINF) ? cout<<"INF " : cout<<dis[i]<<" " ;
            // cout<<endl;
            
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
    	int V, E, src;
    	cin >> V >> E >> src;

    	vector<pair<int,int>> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v, wt;
    		cin >> u >> v >> wt;
    		adj[u].push_back({v,wt});
            // adj[v].push_back(u);
    	}

    	Solution obj;
    	obj.longestpath(src,V, adj);
    }

    return 0;
}

  // } Driver Code Ends