// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    vector<bool> vis=vector<bool>(100005,false);
	vector<bool> cur=vector<bool>(100005,false);
	vector<int> p= vector<int> (100005,-1);
	bool check(int v, vector<int> adj[]){
	   queue<int>q;
	   vis[v]=true;
	   q.push(v);
	   p[v]=-1;
        //  cout<<v<<" "<<v<<" "<<p[v]<<endl;
	   while(q.size()){
	       int x= q.front();
	       q.pop();
	       for(int i : adj[x]){
	        //    cout<<i<<" "<<x<<" "<<p[x]<<endl;
	           if(vis[i]&&p[x]!=i)return true;
	           if(!vis[i]){
	               vis[i]=true;
	               p[i]=x;
                   q.push(i);
	           }
	       }
	   }
	   return false;
}
	
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            bool t = check(i,adj);
	            if(t)return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends