int Solution::numTrees(int A) {
    int ans[A+1];
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    ans[3]=5;
    for(int i=4;i<=A;i++){
        ans[i]=0;
        for(int j=0;j<i;j++){
            ans[i]+=(ans[j]*ans[i-j-1]);
        }
    }
    return ans[A];
}
