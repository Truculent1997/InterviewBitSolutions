int dp[10001][201];
bool solve(const string a,const string b,int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==a.length()&&j==b.length())return true;
    if(i>a.length())
    {
        return false;
    }
    if(b[j]=='?')
    {
        return dp[i][j]=solve(a,b,i+1,j+1);
    }
    else if(b[j]!='*'){
        if(b[j]==a[i])return dp[i][j]=solve(a,b,i+1,j+1);
        return dp[i][j]=false;
    }
    else if(b[j]=='*')
    {
        for(int k=i;k<=a.length();k++)
        {   bool f=0;
            f=solve(a,b,k,j+1);
            if(f)return dp[i][j]=f;
        }
        return dp[i][j]=false;
    }
    
}
int Solution::isMatch(const string A, const string B) {
    for(int i=0;i<10001;i++)for(int j=0;j<201;j++)dp[i][j]=-1;
    if(A==B)return 1;
    return solve(A,B,0,0);
}
