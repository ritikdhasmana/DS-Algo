//hackerearth
#include <bits/stdc++.h>
using namespace std;

int counter=0;
vector<int> intime(100004);
vector<int> outime(100004);
void dfs(int src,vector<bool>& vis,vector<int>g[])
{
    vis[src]=true;
    intime[src]=counter++;
    for(int x : g[src]){
        if(!vis[x])dfs(x,vis,g);
    }
    outime[src]=counter++;
}
bool check(int x,int y)
{
    if(intime[x]>intime[y]&&outime[x]<outime[y])return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    std::vector<int> g[n+1];
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool>vis(n+1,false);
    dfs(1,vis,g);
    for (int i = 1; i <= n; ++i)
    {
        cout<<i<<" " <<intime[i]<<endl;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int s,x,y;
        cin>>s>>x>>y;
        if(!check(x,y)&&!check(y,x))cout<<"NO"<<endl;
        else if(s){
            if(!check(x,y))cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
          }else if(!s){
            if(!check(y,x))cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}