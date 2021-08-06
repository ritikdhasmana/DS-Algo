// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res="";
		    queue<char>q;
		    int freq[27]={0};
		    char ch='#';
		    for(int i=0;i<A.size();i++){
		        freq[A[i]-'a']++;
		      //  cout<<A[i]<<freq[A[i]-'a']<<" "<<A[i]-'a'<<" ";
		        q.push(A[i]);
		        while(q.size()&&freq[q.front()-'a']>1)
                 {
                    //  cout<<q.top()<<"sdf ";
                     q.pop();
                 }
		        if(!q.size()){
		            if(freq[A[i]]==1)res+=A[i];
		            
		            else res+=ch;
		          //  cout<<res<<endl;
		        }else{
		            res+=q.front();
		        }
		        
		        
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends