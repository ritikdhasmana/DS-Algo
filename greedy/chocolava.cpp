//SPOJ 


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

void solve()
{
    ll n,m;
    cin>>m>>n;
    vector<int>xc(m-1),yc(n-1);
    for(int i=0;i<m-1;i++)cin>>xc[i];
    for(int i=0;i<n-1;i++)cin>>yc[i];    
    sort(all(xc),greater<int>());
    sort(all(yc),greater<int>());
    ll i=0,j=0,hp=1,vp=1,ans=0;//horizontal and vertical pieces..
    while(i<m-1&&j<n-1)
    {
        if(xc[i]>=yc[j])
        {
            ans+=xc[i++]*vp;
            hp++;
        }
        else
        {
            ans+=yc[j++]*hp;
            vp++;
        }
    }
    while(i<m-1)
    {
        ans+=xc[i++]*vp;
        hp++;
    }
    while(j<n-1)
    {
        ans+=yc[j++]*hp;
        vp++;
    }
    cout<<ans<<endl;
}


int main()
{
    fast_io;
    ll t=1,i=1;
    cin>>t;
    while(t--)
    {
        solve();
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
