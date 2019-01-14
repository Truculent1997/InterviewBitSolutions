int Solution::solve(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int dp[m+1][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0){
                if(A[j][i]==1)dp[j][i]=1;
                else dp[j][i]=0;
            }
            else {
                if(!A[j][i])dp[j][i]=0;
                else dp[j][i]=dp[j-1][i]+1;
            }
        }
    }
    for(int i=0;i<m;i++){
        int count[m+1];
        for(int i=0;i<=m;i++)count[i]=0;
        for(int j=0;j<n;j++){
            count[dp[i][j]]++;
        }
        int col=0;
        for(int k=m;k>=0;k--){
            if(count[k]>0){
                for(int z=0;z<count[k];z++){
                    dp[i][col]=k;
                    col++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           ans=max(ans,dp[i][j]*(j+1)); 
        }
    }
    return ans;
}
