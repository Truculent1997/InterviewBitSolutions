int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int dp[m+1][n+1];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                if(A[i][j])dp[i][j]=1;
                else dp[i][j]=0;
            }
            else{
                if(A[i][j])dp[i][j]=dp[i][j-1]+1;
                else dp[i][j]=0;
            }
            //cout<<dp[i][j]<<"  ";
        }
        //cout<<endl;
    }
    stack<int> s;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s.empty()){
                //cout<<j<<" <-j ";
                s.push(j);
            }
            else{
                if(dp[j][i]>dp[s.top()][i]){
                    s.push(j);
                }
                else if(dp[j][i]<dp[s.top()][i]){
                    int k=j;
                    while(!s.empty()&&dp[j][i]<dp[s.top()][i]){                        
                        int cur=(j-s.top())*dp[s.top()][i];
                        dp[s.top()][i]=dp[j][i];
                        k=s.top();
                        ans=max(cur,ans);
                        s.pop();
                    }
                    s.push(k);
                }
            }
        }
        while(!s.empty()){
                    int cur=(m-s.top())*dp[s.top()][i];
                    ans=max(cur,ans);
                    s.pop();
            }
    }
    return ans;
}
