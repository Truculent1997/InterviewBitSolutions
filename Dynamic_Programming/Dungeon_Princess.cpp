int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m=A.size()-1;
    int n=A[0].size()-1;
    int dp[m+1][n+1];
    for(int i=m;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(i<m&&j<n){
                int mini=min(dp[i+1][j],dp[i][j+1]);
                if(A[i][j]>=mini)dp[i][j]=1;
                else dp[i][j]=mini-A[i][j];
            }
            else if(i<m){
                if(A[i][j]>=dp[i+1][j])dp[i][j]=1;
                else dp[i][j]=dp[i+1][j]-A[i][j];
            }
            else if(j<n){
                if(A[i][j]>=dp[i][j+1])dp[i][j]=1;
                else dp[i][j]=dp[i][j+1]-A[i][j];
            }
            else{
                if(A[i][j]>0)dp[i][j]=1;
                else dp[i][j]=abs(A[i][j])+1;
            }
        }
        //cout<<"\n";
    }
    return dp[0][0]>0?dp[0][0]:1;
}
