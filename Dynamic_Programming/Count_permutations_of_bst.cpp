long long int dp[51][51];
long long int comb[52][52];
long long int mod=1000000007;
long long int smooth(long long int A){
    return (A+mod)%mod;
}
long long int solve(int B,int A){
    //cout<<B<<"   "<<A<<endl;
    if(dp[B][A]!=-1)return dp[B][A];
    //cout<<"here";
    if(B<=1){
        if(A==0)return dp[B][A]=1;
        else if(A>0)return dp[B][A]=0;
        else return 0;
    }
    if(A==0){
        if(B==1||B==0)return dp[B][A]=1;
        else return dp[B][A]=0;
    }
    //cout<<"phere";
    int res=0;
    for(int i=1;i<=B;i++){
        int l=i-1;
        int r=B-i;
        int res1=0;
        for(int i=0;i<=A-2;i++){
            res1=smooth(res1+smooth(solve(l,i)*solve(r,A-1)));
        }
        for(int j=0;j<=A-2;j++){
            res1=smooth(res1+smooth(solve(l,A-1)*solve(r,j)));
        }
        res1=smooth(res1+smooth(solve(l,A-1)*solve(r,A-1)));
        res=smooth(res+smooth(res1*comb[l+r][l]));
    }
    return dp[B][A]=smooth(res);
}
int Solution::cntPermBST(int A, int B) {
    for(int i=0;i<=50;i++){
        for(int j=0;j<=50;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=50;i++){
        for(int j=0;j<=i;j++){
            if(i==1||j==0)comb[i][j]=1;
            else if(j==i)comb[i][j]=1;
            else{
                comb[i][j]=smooth(comb[i-1][j-1]+comb[i-1][j]);
            }
        }
    }
    //cout<<comb[3][2]<<"adsa\n";
    return solve(A,B);
    
}
