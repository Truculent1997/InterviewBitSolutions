Problem: https://www.interviewbit.com/problems/rearrange-array/
void Solution::arrange(vector<int> &A) {
    int n=A.size();
    for(int i=0;i<n;i++)A[i]=n*A[i]+(A[i]<i?A[A[i]]/n:A[A[i]]);
    for(int i=0;i<n;i++)A[i]=(A[i])%n;
 }
