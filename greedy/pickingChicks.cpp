//https://www.spoj.com/problems/GCJ101BB/   

#include<bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define fi first
#define endl '\n'
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pob pop_back
#define vll vector<ll>
#define mll multiset<ll>
#define sll set<ll>
#define mpll map<ll,ll>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
// cout.tie(NULL);
#define deb(x) cout<< #x <<":" <<" "<<x<<endl;
using namespace std;

// const int mod = 1e6+1;
const int mod= 1e9+7 ;
const int Max = 3*100000+5;



/*---------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

ll time(ll dis,ll v)
{
    return dis/v;
}

void solve(ll c)
{
    ll n,k,b,t,hurdle=0;
    cin>>n>>k>>b>>t;
    vector<int>pos(n),vel(n);
    for(int i=0;i<n;i++)cin>>pos[i];
    for(int i=0;i<n;i++)cin>>vel[i];    

    ll chic=0,swaps=0;    
    for(ll i=n-1;i>=0;i--)
    {
        ll dis=b-pos[i];
        // ll tim=time(dis,vel[i]);
        ll cancover = t*vel[i];
        // cout<<tim<<endl;
        if(dis>cancover)hurdle++;
        else
        {
            swaps+=hurdle;
            chic++;
        }
        if(chic==k)break;
    }
    if(chic<k)cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;  
    else   cout<<"Case #"<<c<<": "<<swaps<<endl; 
}


int main()
{
    fast_io;
    ll t=1,i=1;
    cin>>t;
    while(t--)
    {
        solve(i++);
    }
    // cin>>t;

    return 0;
}
/*
2 3 4
6 5 1
4 2 3 9

2 4 6
5 3 1
3 1 5 9
*/
