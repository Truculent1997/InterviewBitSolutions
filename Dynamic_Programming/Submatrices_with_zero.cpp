int Solution::solve(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j+1]=dp[i+1][j]+A[i][j]+dp[i][j+1]-dp[i][j];
            //cout<<dp[i+1][j+1]<<"   ";
        }
        //cout<<endl;
    }
    long ans=0;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            unordered_map<int,int> count;
            count[0]=1;
            for(int k=1;k<=n;k++){
                int val=dp[j][k];
                int val2=dp[i-1][k];
                val=val-val2;
                ans+=count[val];
                count[val]++;
            }
        }
    }
    return ans;
}
