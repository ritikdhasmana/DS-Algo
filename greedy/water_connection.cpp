// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int>con(n+1,0),child(n+1,0),diameter(n+1,10000);
        vector<vector<int>>ans;
        con[0]=-1;
        // map<int,int>mp;
        for(int i=0;i<p;i++)
        {
            con[b[i]]=-1;
            child[a[i]]=b[i];
            diameter[a[i]]=min(diameter[a[i]],d[i]);
            diameter[b[i]]=min(diameter[b[i]],d[i]);
            // mp[a[i]]=i;
            // mp[b[i]]=i;
        }

        for(int i=1;i<n+1;i++)
        {
            if(con[i]!=-1)
            {
                vector<int>v(3);
                // cout<<i<<" "<<diameter[i]<<" loop-- ";
                int st=i,end=i,dia=diameter[st];
                while(child[end]!=0)
                {
                    // cout<<end<<" "<<child[end]<<" "<<diameter[child[end]]<<endl;
                    end=child[end];
                    dia=min(dia,diameter[end]);

                }
                if(st!=end){v[0]=st;
                v[1]=end;
                v[2]=dia;
                ans.push_back(v);}
            }
            
        }
        // for(int i=0;i<n+1;i++)
        // {
        //     cout<<con[i]<<" "<<child[i]<<" "<<dia[i]<<endl;
        // }
        return ans;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends