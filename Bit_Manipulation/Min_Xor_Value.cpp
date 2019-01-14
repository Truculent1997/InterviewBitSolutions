int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    long ans=LONG_MAX;
    for(int i=1;i<A.size();i++){
        if(ans>(A[i]^A[i-1]))ans=A[i]^A[i-1];
    }
    return ans;
}
