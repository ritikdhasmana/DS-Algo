// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>g){
	    // Code here
	    int INF=1000000;
	    int x=1;
	    vector<int>dis(n,INF);
	    dis[0]=0;
	    for(int i=0;i<n;i++)
	    {
	        x=0;
	        for(auto it : g)
	        {
	            int u=it[0];
	            int v=it[1];
	            int wt=it[2];
	            if(dis[u]!=INF&&dis[u]+wt<dis[v])
	            {
	                dis[v]=dis[u]+wt;
	                x=1;
	            }
	        }
	    }
	    return x;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends