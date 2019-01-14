int Solution::jump(vector<int> &A) {
    int cstep=0;
    int cmax=0;
    int jump=0;
    int pos=0;
    for(int i=0;i<A.size()-1;i++)
    {
        if(i>cmax)return -1;
        if(i==A.size()-1)return jump;
        if(cstep==i)
        {
            jump++;
            cstep=cmax-i-pos;
        }
        if(cmax>=i)
        {
            if(i+A[i] > cmax){cmax=i+A[i];pos=i;}
        }
    }
    return jump;
}
