int dp[2][1001][1001];
int solve(vector<int> A,int s,int e,int player){
    if(dp[player][s][e]!=-1)return dp[player][s][e];
    if(s+1==e){
        dp[player][s][e]=max(A[s],A[e]);
        dp[!player][s][e]=min(A[s],A[e]);
        return dp[player][s][e];
    }
    else{
        dp[player][s][e]=max(A[s]+(min(solve(A,s+2,e,!player),solve(A,s+1,e-1,!player))),A[e]+(min(solve(A,s+1,e-1,!player),solve(A,s,e-2,!player))));        
        return dp[player][s][e]; 
    }
}
int Solution::maxcoin(vector<int> &A) {
    int n=A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[0][i][j]=-1;
            dp[1][i][j]=-1;
        }
    }
    return solve(A,0,n-1,0);
}
