int Solution::trap(const vector<int> &A) {
    int l=0;
    int r=A.size()-1;
    int leftmax=0;
    int rightmax=0;
    int ans=0;
    while(l<r){
        leftmax=max(leftmax,A[l]);
        rightmax=max(rightmax,A[r]);
        if(leftmax<rightmax){
            ans+=(leftmax-A[l]);
            l++;
        }
        else{
            ans+=(rightmax-A[r]);
            r--;
        }
    }
    return ans;
}
