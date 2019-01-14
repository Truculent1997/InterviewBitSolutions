int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(int i=0;i<=31;i++){
        int c=0;
        for(int j=0;j<A.size();j++)c+=((A[j]&(1<<i))>0?1:0);
        ans|=((c%3)<<i);
    }
    return ans;
}
