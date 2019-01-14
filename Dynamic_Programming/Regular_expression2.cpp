int Solution::isMatch(const string A, const string B) {
    int m=A.length();
    int n=B.length();
    bool dp[m+1][n+1];
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=m;i++){
        dp[i][0]=false;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           dp[i+1][j+1]=false;
           if((A[i]==B[j])||(B[j]=='.'))dp[i+1][j+1]=dp[i][j];
           else if(B[j]=='*'){
               if(B[j-1]!=A[i]&&B[j-1]!='.'){
                   dp[i+1][j+1]=dp[i+1][j-1];
               }
               else{
                   dp[i+1][j+1]=(dp[i+1][j-1]||dp[i][j+1]||dp[i+1][j]);
               }
           }
        }
    }
    return dp[m][n];
}
