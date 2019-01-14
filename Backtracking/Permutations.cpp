void swap(int l,int r,vector<int> &A){
    int temp=A[l];
    A[l]=A[r];
    A[r]=temp;
}
void permutes(int l,int r,vector<vector<int>> &ans,vector<int> &A){
    if(l==r){
        ans.push_back(A);
    }
    else{
        for(int i=l;i<=r;i++){
            swap(l,i,A);
            permutes(l+1,r,ans,A);
            swap(l,i,A);
        }
    }
    
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    permutes(0,A.size()-1,ans,A);
    return ans;
}
