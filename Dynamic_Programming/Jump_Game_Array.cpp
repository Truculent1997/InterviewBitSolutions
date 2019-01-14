int Solution::canJump(vector<int> &A) {
    int n=A.size();
    bool vis[n+1];
    for(int i=0;i<=n;i++){
        vis[i]=false;
    }
    vis[0]=true;
    for(int i=0;i<n-1;i++){
        if(vis[i]){
            if(i+A[i]>=n){
                return true;
            }
            for(int j=i+1;j<=i+A[i];j++)vis[j]=true;
        }
    }
    return vis[n-1];
}
