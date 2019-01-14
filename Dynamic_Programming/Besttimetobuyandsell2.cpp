int Solution::maxProfit(const vector<int> &A) {
    if(A.size()<2)return 0;
    int s1,s2,s3,s4;
    s2=INT_MIN;
    s3=INT_MIN;
    s4=INT_MIN;
    s1=-A[0];
    for(int i=1;i<A.size();i++){
        s1=max(s1,-A[i]);
        s2=max(s2,s1+A[i]);
        s3=max(s3,s2-A[i]);
        s4=max(s4,s3+A[i]);
    }
    return max(0,s4);
}
