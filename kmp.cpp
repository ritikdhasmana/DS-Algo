// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
        int* kmp(string pat){
            int * arr = new int[pat.length()+1];
            int ind=0;
            arr[0]=0;
            for(int i=1;i<pat.length();){
                if(pat[i]==pat[ind]){
                    ind++;
                    arr[i]=ind;
                    i++;
                }
                else
                {
                    if(ind!=0)ind=arr[ind-1];
                    else
                    {
                        arr[i++]=0;

                    }
                }
            }
             // for(int i=0;i<pat.length();i++)cout<<arr[i]<<endl;
            return arr;
        }

        int comparr(string pat,string st){
            int* lsp = kmp(pat);
            int i=0,j=0;

            while(i<st.length()&&j<pat.length()){
                if(pat[j]==st[i]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0)j=lsp[j-1];
                    else
                        i++;
                }
                
            }
            if(j==pat.length())return i-j;
            cout<<j<<endl;
            return -1;
        }


};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string str,s;
        cin >> str;
        cin>>s;
        Solution obj;
        int ans = obj.comparr(s,str);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends