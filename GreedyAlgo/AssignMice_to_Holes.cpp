int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int mini=0;
    for(int i=0;i<A.size();i++){
        mini=max(mini,abs(A[i]-B[i]));
    }
    return mini;
}
