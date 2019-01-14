int Solution::longestSubsequenceLength(const vector<int> &A) {
    int m=A.size();
    int idp[m+1];
    int ddp[m+1];
    for(int i=0;i<=m;i++){
        idp[i]=0;
        ddp[i]=0;
    }
    idp[0]=1;
    for(int i=1;i<A.size();i++){
        int j=i;
        idp[i]=1;
        while(j>=0){
            if(A[i]>A[j]){
                idp[i]=max(idp[i],idp[j]+1);
            }
            j--;
        }
        //cout<<idp[i]<<"   ";
    }
    //cout<<endl;
    ddp[m-1]=1;
    for(int i=m-2;i>=0;i--){
        int j=i;
        while(j<=m-1){
            if(A[i]>A[j]){
                ddp[i]=max(ddp[i],ddp[j]+1);
            }
            j++;
        }
        //cout<<idp[i]<<"   ";
    }
    //cout<<endl;
    int ans=0;
    for(int i=0;i<m;i++){
        ans=max(ans,ddp[i]+idp[i]-1);
    }
    return ans;
}
