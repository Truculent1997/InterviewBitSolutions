int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n=A.size();
    int i=0;
    int sum=0;
    int s=-1;
    while(i<2*n){
        if(s==i%n)return s;
        else if(sum+(A[i%n])>=B[i%n]){
            if(s==-1)s=(i%n);
            sum=sum+A[i%n]-B[i%n];
        }
        else{
            sum=0;
            s=-1;
        }
        i++;
    }
    return -1;
}
