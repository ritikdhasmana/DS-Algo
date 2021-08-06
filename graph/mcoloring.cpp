// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool check(int c,bool g[101][101],vector<int>&color,int v,int n)
{
    for(int i=0;i<n;i++)
    {
        if(g[v][i]&&color[i]==c)return false;
    }
    return true;
}
bool coloring(bool g[101][101],vector<int>&color,int m,int v,int n)
{
    if(v==n)return true;
    
    for(int i=1;i<=m;i++)
    {
        if(check(i,g,color,v,n)){
            color[v]=i;
            if(coloring(g,color,m,v++,n))return true;
            color[v]=0;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    
    vector<int>color(101,0);
    return coloring(graph,color,m,0,V);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends