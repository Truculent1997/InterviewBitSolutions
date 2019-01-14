int smooth(long long int res){
    return (res+10000003)%10000003;
}
int Solution::seats(string A) {
    int n=A.length();
    vector<int> loc;
    for(long i=0;i<n;i++){
        if(A[i]=='x')loc.push_back(i);
    }    
    long long int sum=0;
    int x=loc.size();
    int c=0;
    for(int i=0;i<x;i++){
         if(i<x/2){
             sum=smooth(sum+(abs(loc[i]-(loc[x/2]-x/2+i))));
         }
         else{
             sum=smooth(sum+abs(loc[i]-(loc[x/2]+i-x/2)));
             c++;
         }
    }
    return sum;
}
