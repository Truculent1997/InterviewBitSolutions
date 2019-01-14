int Solution::lis(const vector<int> &A) {
    int n=A.size();
    if(n<=1)return n;
    vector<int> ans;
    ans.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(A[i]<ans[0])ans[0]=A[i];
        else if(A[i]>ans[ans.size()-1])ans.push_back(A[i]);
        else{
            int c=lower_bound(ans.begin(),ans.end(),A[i])-ans.begin();
            ans[c]=A[i];
        }
    }
    return ans.size();
}
