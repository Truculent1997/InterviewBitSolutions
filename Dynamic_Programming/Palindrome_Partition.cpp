int Solution::minCut(string A) {
    int n=A.length();
    int dp[n+1][n+1];
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(int gap=1;gap<n-1;gap++){
        for(int k=0;k<n-gap;k++){
            if(gap==1){
                if(A[k]==A[k+1])dp[k][k+1]=0;
                else dp[k][k+1]=1;
            }
            else{
                    if(A[k]==A[k+gap]&&dp[k+1][k+gap-1]==0)
                    {
                        dp[k][k+gap]=dp[k+1][k+gap-1];
                    }
                    else{
                        int mini=100001;
                        for(int m=0;m<gap;m++){
                            mini=min(mini,1+dp[k][k+m]+dp[k+m+1][k+gap]);
                        }
                        dp[k][k+gap]=mini;
                    }
                }
             cout<<dp[k][k+gap]<<"   ";   
        }
        cout<<endl;
    }
    return dp[0][n-1];
}
