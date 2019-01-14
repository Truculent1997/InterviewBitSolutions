long smooth(long A){
    return (A+1000000007)%1000000007;
}
int Solution::solve(int A, int B) {
    int dp[A+1][B+1];
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=B&&i<=9;i++){
        dp[1][i]=1;
    }
    for(int i=1;i<A;i++){
        for(int j=1;j<=B;j++){
            for(int k=0;k<=9;k++){
                if(j+k<=B){
                    dp[i+1][j+k]=smooth(dp[i+1][j+k]+dp[i][j]);
                }   
            }
        }
    }
    return dp[A][B];
}
