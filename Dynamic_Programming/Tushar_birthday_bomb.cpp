int dp[1001][1001];
int knapsack(int x,const vector<int> &B,const vector<int> &C){
    int n=C.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i==0)dp[i][j]=1000005;
            else if(j==0)dp[i][j]=0;
            else if(j-B[i-1]>=0){
                if(C[i-1]+dp[i][j-B[i-1]]<dp[i-1][j]){
                    dp[i][j]=C[i-1]+dp[i][j-B[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }    
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][x];
}
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    long long int sum=0;
    int m=0;
    for(int i=0;i<A.size();i++){
        m=max(m,A[i]);
        //sum+=knapsack(A[i],B,C);    
    }
    knapsack(m,B,C);
    for(int i=0;i<A.size();i++){
        sum+=dp[C.size()][A[i]];
    }
    return sum;
}
