
/*In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.*/
#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int num=ceil((double)N/(K+1));
        vector<int> v;
        // cout<<num<<endl;
        int ans=0;
        sort(candies,candies +N);
        for(int i=0;i<num;i++)
        {
            ans+=candies[i];
        }
        v.push_back(ans);
        ans=0;
        for(int i=N-1;i>=N-num;i--)ans+=candies[i];
        v.push_back(ans);
        return v;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends