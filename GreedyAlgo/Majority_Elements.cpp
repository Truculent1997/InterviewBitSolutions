int Solution::majorityElement(const vector<int> &A) {
    int n=A.size();
    int cand=-1;
    int c=0;
    for(int i=0;i<n;i++){
        if(c!=0&&A[cand]==A[i]){
            c++;
        }
        else if(c!=0&&A[cand]!=A[i]){
            c--;
        }
        if(c==0){
            cand=i;
        }
    }
    return A[cand];
}
