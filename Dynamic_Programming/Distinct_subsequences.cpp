int Solution::numDistinct(string A, string B) {
    int n=A.length();
    int m=B.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)dp[i][j]=0;
            else if(B[i-1]==A[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=dp[i][j-1];
            cout<<dp[i][j]<<"  ";
        }
        cout<<"\n";
    }
    return dp[m][n];
}
