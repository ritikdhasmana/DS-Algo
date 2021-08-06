stack<long long >st;
        long long ans=0,i=0;
        while(i<n){
            if(!st.size()||arr[st.top()]<=arr[i])st.push(i++);
            else{
                int x=st.top();
                st.pop();
                long long area= arr[x]*(i-(st.size()?st.top():0));
                ans=max(area,ans);
            }
        }
        while(st.size()){
                int x=st.top();
                st.pop();
                // cout<<x<<" " <<arr[x]<<"  "<<ans<<endl;
                long long area= arr[x]*((n-1)-(st.size()?st.top():0));
                ans=max(area,ans);
        }
        return ans;