// hackerrank question https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <bits/stdc++.h>
#define int     long long int
using namespace std;


void dfs(int src,vector<int>adj[],vector<bool>& vis,int& cnt)
{
    vis[src]=true;
    cnt++;
    for(int x: adj[src])
    {
        if(!vis[x])dfs(x,adj,vis,cnt);
    }
}

int32_t main(){
    int n,p;
    cin>>n>>p;
    std::vector<int> adj[n];
    for (int i = 0; i < p; ++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    vector<bool>vis(n,false);   
    vector<int>pairs;
    for(int i=0;i<n;i++){
        if(!vis[i])
        {
            int cnt=0;
            dfs(i,adj,vis,cnt);
            pairs.push_back(cnt);
        }
    }
    int ans=(n*(n-1))/2;
    for(int i=0;i<pairs.size();i++)
    {
        int x=pairs[i];
        ans= ans- (x*(x-1))/2;
    }
    cout<<ans<<endl;
    return 0;
}  
