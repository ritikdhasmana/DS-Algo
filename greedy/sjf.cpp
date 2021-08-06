// Program for Shortest Job First (or SJF) CPU Scheduling | Set 1 (Non- preemptive)

#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>a,vector<int>b)
{
    if(a[1]==b[1])
    {
        if(a[2]==b[2])return a[0]<b[0];
        return a[2]<b[2];
    }
    return a[1]<b[1];
}

int main()
 {
     int t=1;
    //  cin>>t;
     while(t--)
     {
        int n, k;
        cin>>n;
        vector<vector<int>>v(n); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++){
                int x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        sort(v.begin(),v.end(),comp);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({v[0][2],v[0][1],v[0][0]});
        int i=1;
        vector<int>ans;
        int time=0;
        while(pq.size())
        {
            int burst=pq.top()[0];
            int id=pq.top()[2];
            pq.pop();
            ans.push_back(id);
            time+=burst;
            while(1)
            {
                if(i<n&&v[i][1]<=time)
                {
                    pq.push({v[i][2],v[i][1],v[i][0]});
                    i++;
                }
                else break;
            }
        }
        // for(auto x:ans)cout<<x<<endl;
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
     }
	
	return 0;
}  