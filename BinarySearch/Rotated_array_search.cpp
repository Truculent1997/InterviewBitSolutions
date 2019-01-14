int ind=-1;
void binarysearch(const vector<int> &A,int l,int r,int item){
    if(ind!=-1)return ;
    if(l<=r){
        int mid=(l+r)/2;
        if(A[mid]==item){ind=mid;}
        if(l==r)return ;
        if(A[mid]>=A[l]){
            if(A[l]<=item&&A[mid]>=item){
                binarysearch(A,l,mid-1,item);
            }
            else{
                binarysearch(A,mid+1,r,item);
            }
        }
        else{
            if(A[mid]<=item&&A[r]>=item)
                binarysearch(A,mid+1,r,item);
            else     
                binarysearch(A,l,mid-1,item);
            return ;
        }
    }
    return ;
}
int Solution::search(const vector<int> &A, int B) {
    int n=A.size();
    ind=-1;
    binarysearch(A,0,n-1,B);
    return ind;
}
