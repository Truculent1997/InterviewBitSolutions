int Solution::minimumTotal(vector<vector<int> > &A) {
   int m=A.size();
   if(m==0)return 0;
   if(m==1)return A[0][0];
   int n=A[m-1].size();
   int dp[2][n];
   for(int i=0;i<2;i++){
       for(int j=0;j<n;j++){
           dp[i][j]=0;
       }
   }
   dp[0][0]=A[0][0];
   int i=1;
   for(;i<n;i++){
       for(int j=0;j<A[i].size();j++){
           if(j==0)
            dp[i%2][j]=dp[(i-1)%2][j]+A[i][j];
           
           else if(j==A[i].size()-1)dp[i%2][j]=dp[(i-1)%2][(j-1)]+A[i][j];
           else{
               dp[i%2][j]=A[i][j]+min(dp[(i-1)%2][(j-1)],dp[(i-1)%2][j]);
           }
       }
   }
   int mini=1000001;    
   for(int j=0;j<A.size();j++){
       mini=min(mini,dp[(i-1)%2][j]);
   }        
   return mini;
}
