int dp[1001][1001];
bool check(string A,string B,string C,int i,int j,int k){
    if(dp[i][j]!=-1)return dp[i][j];
    if(A.length()==i&&B.length()==j)return true;
    bool f=false;
    if(k==C.length())return false;
    if(i<A.length()){
        if(A[i]==C[k])f=check(A,B,C,i+1,j,k+1);
    }
    if(!f&&j<B.length()){
        if(B[j]==C[k])f=check(A,B,C,i,j+1,k+1);
    }    
    return dp[i][j]=f;
}
int Solution::isInterleave(string A, string B, string C) {
    int m=A.length();
    int n=B.length();
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    return check(A,B,C,0,0,0);
}
