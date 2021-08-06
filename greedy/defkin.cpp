/*Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.
SPOJ */



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


void solve()
{
    
    int w,h,n;
    cin>>w>>h>>n;
    if(n==0){
        cout<<w*h<<endl;
        return;
    }
    vector<int> ht,wd;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        ht.push_back(b);
        wd.push_back(a);
    }
    ht.push_back(h+1);
    wd.push_back(w+1);
    ht.push_back(0);
    wd.push_back(0);
    sort(all(ht));
    sort(all(wd));
    int l=0,b=0;
    for (int i = 1; i < ht.size(); ++i)
    {
        l=max(l,ht[i]-ht[i-1]-1);
    }
    for (int i = 1; i < wd.size(); ++i)
    {
        b=max(b,wd[i]-wd[i-1]-1);
    }
    cout<<(l)*(b)<<endl;
}


int main()
{
    fast_io;
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
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
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <iostream>
// #include <functional>
// #include <iomanip>
// #include <cstdio>
// #include <queue>
// #include <cstring>
// #include <cstdlib>
// #include <cassert>
// #include <stdio.h>
// #include <set>
// using namespace std;

// inline void inp( int &n )
// {
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
// }

// void Swap(int &a,int &b){
//     int temp = a;
//     a = b;
//     b =  temp;
// }

// void QuickSort(int * A, int Left, int Right){
//     int i = Left, j = Right;
//     int pivot = A[(Left + Right) / 2];
//     /* partition */
//     while (i <= j) {
//         while (A[i] < pivot)
//             i++;
//         while (A[j] > pivot)
//             j--;
//         if (i <= j) {
//             Swap(A[i],A[j]);
//             i++;
//             j--;
//         }
//     }
    
//     /* recursion */
//     if (Left < j)
//         QuickSort(A, Left, j);
//     if (i < Right)
//         QuickSort(A, i, Right);
// }

// int main () {
//     int t;
//     int w, h, n;
//     int finalRs, tempMaxX, tempMaxY;
//     int x[40002];
//     int y[40002];
//     inp(t);
//     for (int z = 0; z < t; z++) {
//         inp(w); inp(h); inp(n);
//         for (int i = 1; i <= n; i++) {
//             inp(x[i]);
//             inp(y[i]);
//         }
//         x[0] = 0;
//         x[n+1] = w + 1;
//         y[0] = 0;
//         y[n+1] = h + 1;
//         QuickSort (x, 0, n+1);
//         QuickSort (y, 0, n+1);
        
//         tempMaxX = 0;
//         for (int i = 1; i <= n+1; i++)
//             tempMaxX = max(tempMaxX, x[i]- x[i-1] - 1);
        
//         tempMaxY = 0;
//         for (int i = 1; i <= n+1; i++)
//             tempMaxY = max(tempMaxY, y[i]- y[i-1] - 1);

//         finalRs = tempMaxX * tempMaxY;
//         cout << finalRs << "\n";
//     }
// }