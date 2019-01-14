int Solution::solve(const vector<int> &A) {
    int m=A.size();
    int sum=0;
    for(int i=0;i<m;i++){
        sum+=A[i];
    }
    int maxj=-1;
    int steps=10001;
    int dp[m+1][sum/2+1];
    for(int i=0;i<=(sum/2 +1);i++)dp[0][i]=10001;
    for(int i=0;i<=m;i++)dp[i][0]=0;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=sum/2;j++){
            dp[i][j]=10001;
            if(j-A[i-1]>=0)dp[i][j]=min(1+dp[i-1][j-A[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
            if(dp[i][j]!=10001&&(maxj<j||(maxj==j&&steps>dp[i][j]))){
                maxj=j;
                steps=dp[i][j];
            }
            //cout<<dp[i][j]<<"    "<<j<<endl;
        }
    }
    
    return steps;
}
