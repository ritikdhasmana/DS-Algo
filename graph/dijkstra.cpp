// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int INF=1e5;




class Solution
{
    public:
    void dijkstra(int src,int n,vector<pair<int,int>>adj[])
    {
        vector<bool>vis(n,false);
        vector<int>p(n,-1);
        vector<int>d(n,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        d[src]=0; 
        // for (int i = 0; i < n; i++)
        // {
            pq.push(make_pair(d[src],src));
        // }
       
        for (int i = 0; i < n-1; i++)
        {
            int len =  pq.top().first;
            int v = pq.top().second;
            // cout<<len<<" "<<v<<endl;
            pq.pop();
            // if(vis[v])continue;
            if(len==INF)break;
            vis[v]=true;
            for(auto x : adj[v])
            {
                int dis1=x.second;
                int u=x.first;
                // cout<<u<<" a - "<<dis1<<" a - "<<d[u]<<endl;
                if(len + dis1 < d[u]){
                    d[u]=len + dis1;
                    p[u]=v;
                }
                if(!vis[u])pq.push(make_pair(d[u],u));
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<d[i]<<" ";
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

        vector<pair<int,int>> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        Solution obj;
        obj.dijkstra(0,V, adj) ;
    }

    return 0;
}

  // } Driver Code Ends