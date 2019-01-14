#define mod 1000000007
long modd(long x)
{
    return (x+mod)%mod;
}
int Solution::chordCnt(int A) {
    long dp[A+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=5;
    for(int i=4;i<=A;i++)
    {
        long ans=0;
        for(int j=0;j<i;j++)
        {
            ans=modd(ans+modd((dp[i-j-1]*dp[j])));
        }
        dp[i]=ans;
    }
    return modd(dp[A]);
}
