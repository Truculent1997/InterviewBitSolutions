double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m=A.size();
    int n=B.size();
    if(m==0&&n==0)return 0;
    int l=0;
    double median;
    int r=m;
    int mid,j;
    while(l<=r){
        //No of elements pick from first array
        mid=(l+r)/2;
        //If u picked mid elements from the first array no of elements needed to be picked from the second array
        j=(m+n+1)/2 -mid;
        //Not Possible to pick after (mid elements picked from A
        if(j<0){
            r=mid-1;
        }
        else if(j>n){
            l=mid+1;
        }
        else if(j>0&&mid<m&&A[mid]<B[j-1]){
            l=mid+1;
        }
        else if(mid>0&&j<n&&A[mid-1]>B[j]){
            r=mid-1;
        }
        else{
                if(mid==0){
                    median=B[j-1];
                }                 
                else if(j==0){
                    median=A[mid-1];
                }
                else{
                    median=max(A[mid-1],B[j-1]);
                }
                break;
        }
    }
    if((m+n)%2)return (double)median;
    else if(mid==m)return (median+B[j])/2.0;
    else if(j==n)return (median+A[mid])/2.0;
    else return (median+min(A[mid],B[j]))/2.0;
}
