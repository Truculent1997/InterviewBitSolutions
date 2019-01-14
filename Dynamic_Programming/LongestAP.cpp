int Solution::solve(const vector<int> &A) {
    int m=A.size();
    if(m<3)return m;
    int dp[m+1][m+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=2;
        }
    }
    sort(A.begin(),A.end());
    //for(int i=0;i<=m-1;i++)dp[i][m-1]=2;
    int ans=2;
    for(int i=m-2;i>=1;i--){
        int j=i-1;int k=i+1;
        while(j>=0&&k<m){
            if(2*A[i]==A[j]+A[k]){
                dp[j][i]=max(dp[j][i],dp[i][k]+1);
                ans=max(ans,dp[j][i]);
                j--;
                k++;
            }
            else if(2*A[i]>A[j]+A[k]){
                k++;
            }
            else{
                j--;
            }
        }
    }    
    return ans;
}
