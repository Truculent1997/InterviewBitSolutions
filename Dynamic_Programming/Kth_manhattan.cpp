vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int m=B.size();
    if(m==0)return {{}};
    int n=B[0].size();
    int dp[m+1][n+1][A+1];
    for(int j=0;j<m;j++){
        for(int k=0;k<n;k++){
                dp[j][k][0]=B[j][k];
        }
    }
    for(int i=1;i<=A;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                dp[j][k][i]=dp[j][k][i-1];
                if(j>=1)dp[j][k][i]=max(dp[j][k][i],dp[j-1][k][i-1]);
                if(k>=1)dp[j][k][i]=max(dp[j][k][i],dp[j][k-1][i-1]);
                if(j<m-1)dp[j][k][i]=max(dp[j][k][i],dp[j+1][k][i-1]);
                if(k<n-1)dp[j][k][i]=max(dp[j][k][i],dp[j][k+1][i-1]);
            }
        }
    }
    vector<vector<int>> ans; 
    for(int j=0;j<m;j++){
        vector<int> temp;
        for(int k=0;k<n;k++){
            temp.push_back(dp[j][k][A]);
        }
        ans.push_back(temp);
    }    
    return ans;
}
