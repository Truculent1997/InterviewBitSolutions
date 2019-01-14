int Solution::findMedian(vector<vector<int> > &A) {
    long  l=1;
    long int r=INT_MAX;
    int m=A.size();
    int n=A[0].size();
    long ans=-1;
    while(l<=r){
        long m1=(l+r)/2;
        long c=0;
        for(int i=0;i<m;i++){
            c+=upper_bound(A[i].begin(),A[i].end(),m1)-A[i].begin();
        }
        if(2*c-1==m*n){
            ans=m1;
            break;
        }
        else if(2*c-1>m*n){
            ans=m1;
            r=m1-1;
        }
        else{
            l=m1+1;
        }
    }
    long long int res=A[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]<=ans&&(m-res>m-A[i][j])){
                res=A[i][j];
            }        
        }
    }
    return l;
}
/*
int Solution::findMedian(vector<vector<int> > &A) {
    int rows=A.size();
    int cols=A[0].size();
    int max=0;
    int min=INT_MAX;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(min>A[i][j]){
                min=A[i][j];
            }
            if(max<A[i][j]){
                max=A[i][j];
            }
        }
    }
    int low=min;
    int high=max;
    int desired=(rows*cols +1)/2  ;
    long ans;
    long mid;
    while(low<high){
        int tot=0;
        mid=low+(high-low)/2;
        for(int i=0;i<rows;i++){
            tot+=(upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        if(tot<desired){
            low=mid+1;
        }
        else
            high=mid;
        
    }
    return low;
}
*/
