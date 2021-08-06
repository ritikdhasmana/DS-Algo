// CPP program to find maximum product of
// a subset.
#include <bits/stdc++.h>
using namespace std;
 
int maxProductSubset(int a[], int n)
{
    if (n == 1)
        return a[0];
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
 
        prod = prod * a[i];
    }
    //  cout<<max_neg<<endl;
    // If there are all zeros
    if (count_zero == n)
        return 0;
    if (count_neg & 1) {
        if (count_neg == 1 &&   count_zero > 0 &&  count_zero + count_neg == n)
            return 0;
        prod = prod / max_neg;
    }
 
    return prod;
}
 
// Driver Code
int main()
{
    int a[] = {  -1, -3, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}