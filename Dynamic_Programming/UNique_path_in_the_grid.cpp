int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int dp[101][101];
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            dp[i][j]=0;
            if(A[i][j]!=1){
                if(i==0&&j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=dp[i][j-1];
                else if(j==0)dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
    }
    return dp[A.size()-1][A[0].size()-1];
}
