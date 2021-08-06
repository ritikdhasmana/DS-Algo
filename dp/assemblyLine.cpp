
#include <bits/stdc++.h>
using namespace std;
#define NUM_LINE 2
#define NUM_STATION 4
 


int carAssembly(int a[][NUM_STATION],int t[][NUM_STATION],int e[],int x[])
{
    int s1= e[0]+a[0][0];
    int s2= e[1]+a[1][0];
    for(int i=1;i<NUM_STATION;i++)
    {
        int first = min(s1+a[0][i],s2+a[0][i]+t[1][i]);
        int second = min(s2+a[1][i],s1+a[1][i]+t[0][i]);
        s1= first;
        s2= second;
    }
    return min( s1+ x[0],s2+ x[1]);
}



int main(){
    int a[][NUM_STATION] = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};
 
    cout << carAssembly(a, t, e, x);
    
    return 0;
}  // } Driver Code Ends