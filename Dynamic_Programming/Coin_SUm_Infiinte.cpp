long smooth(long num){
    return (num%1000007)%1000007;
}
int Solution::coinchange2(vector<int> &A, int B) {
    long dp[B+1];
    for(int i=0;i<=B;i++)dp[i]=0;
    dp[0]=1;
    for(int i=0;i<A.size();i++){
       for(int j=A[i];j<=B;j++){
           dp[j]=smooth(dp[j]+dp[j-A[i]]);
       }
    }
    return dp[B];
}
