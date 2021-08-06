// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int INF=1e5;
struct disjoint
{
    int parent;
    int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<disjoint>dsuf;
int find(int a)
{
    if(dsuf[a].parent==-1)return a;
    else return dsuf[a].parent= find(dsuf[a].parent);
}

void union_op(int a,int b){
    int ra =dsuf[a].rank;
    int rb= dsuf[b].rank;
    if(ra<rb)dsuf[a].parent=b;
    else if(rb<ra)dsuf[b].parent=a;
    else{
        dsuf[a].parent=b;
        dsuf[b].rank++;

    }
}
bool comp(Edge a,Edge b)
{
    return a.wt < b.wt;
}
class Solution
{
    public:
    void kruskal(int v, int e,vector<Edge>adj)
    {
        sort(adj.begin(),adj.end(),comp);
        vector<Edge>mst;
        // for (int i = 0; i < e; i++)
        // {
        //     /* code */cout<< adj[i].wt<<" ";
        // }
        int i=0,j=0;
        while(i<v-1&&j<e){
            int fp = find(adj[j].src);
            int dp= find(adj[j].dst);
            if(fp==dp){
                j++;
                continue;
            }
            union_op(fp,dp);
            mst.push_back(adj[j]);
            i++;
        }
        cout<<"mst - "<<endl;
        for (int i = 0; i < v-1; i++)
        {
            cout<<mst[i].src<<" "<<mst[i].dst<<" "<<mst[i].wt<<endl;
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

        dsuf.resize(V);
        for (int i = 0; i < V; i++)
        {
            dsuf[i].parent=-1;
            dsuf[i].rank=0;
        }
        
        vector<Edge> adj;
        Edge temp;
        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            temp.src=u;
            temp.dst=v;
            temp.wt=w;
            adj.push_back(temp);
            // adj[u].push_back(make_pair(v,w));
            // adj[v].push_back(make_pair(u,w));
        }

        Solution obj;
        obj.kruskal(V, E, adj) ;
    }

    return 0;
}

  // } Driver Code Ends