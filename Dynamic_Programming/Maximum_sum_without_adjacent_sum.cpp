int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    if(n==0)return 0;
    if(n==1)return max(A[0][0],A[1][0]);
    for(int i=2;i<n;i++){
        if(i==2){
         A[0][i]+=max(A[0][i-2],A[1][i-2]);
         A[1][i]+=max(A[0][i-2],A[1][i-2]);    
        }
        else{
            A[0][i]+=max(max(A[0][i-2],A[1][i-2]),max(A[0][i-3],A[1][i-3]));
            A[1][i]+=max(max(A[0][i-2],A[1][i-2]),max(A[0][i-3],A[1][i-3]));    
        }
        
        //cout<<A[0][i]<<"  "<<A[1][i]<<endl;
    }
    // for(int i=0;i<A[0].size();i++)cout<<A[0][i]<<" ";cout<<"\n";
    // for(int i=0;i<A[0].size();i++)cout<<A[1][i]<<" ";cout<<"\n";
    return max(max(A[0][n-2],A[1][n-2]),max(A[0][n-1],A[1][n-1]));
}
