int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    if(n<1)return 0;
    int mini=A[0];
    int ans=0;
    for(int i=1;i<n;i++){
        if(mini>A[i])
            mini=A[i];
        else{
            ans=max(ans,A[i]-mini);
        }    
    }
    return ans;
}
