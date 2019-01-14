int l;
int dp[1001][1001];
long long int solve(int white[],int black[],int rem,int ind,int last){
    if(dp[rem][ind]!=-1)return dp[rem][ind];
    if(rem==1){
        return dp[rem][ind]=(white[l]-white[last])*(black[l]-black[last]);    
    }
    else{
        if(l-ind+1<rem)return 1000000;
        int ans=1000000;
        for(int i=ind;i<=l-rem+1;i++){
            int one=(white[i]-white[last])*(black[i]-black[last])+solve(white,black,rem-1,i+1,i);
            ans=min(ans,one);
        }
        return dp[rem][ind]=ans;
    }
}
int Solution::arrange(string A, int B) {
    l=A.length();
    if(l<B)return -1;
    for(int i=0;i<=l;i++){
        for(int j=0;j<=l;j++){
            dp[i][j]=-1;
        }
    }
    int white[l+1],black[l+1];
    white[0]=0;
    black[0]=0;
    for(int i=0;i<l;i++){
        if(A[i]=='W'){
            white[i+1]=1;
            black[i+1]=0;
        }
        else{
            white[i+1]=0;
            black[i+1]=1;
        }
        white[i+1]+=white[i];
        black[i+1]+=black[i];
    }
    long ans=solve(white,black,B,1,0);
    if(ans==1000000)return -1;
    return ans;
}
