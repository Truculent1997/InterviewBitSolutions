int Solution::candy(vector<int> &A) {
    vector<int> s(A.size()+1);
    int ans=0;
    for(int i=0;i<A.size();i++){
        if(i==0)s[i]=1;
        else if(A[i-1]==A[i])s[i]=1;
        else if(A[i-1]<A[i])s[i]=s[i-1]+1;
        else if(A[i-1]>A[i]&&s[i-1]>1)s[i]=1;
        else{
            s[i]=1;
            int j=i-1;
            while(j>=0&&(A[j]>A[j+1])&&(s[j]<=s[j+1])){
                s[j]=s[j+1]+1;
                j--;
            }
        }
    }
    long long int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=s[i];
    }
    return sum;
}
