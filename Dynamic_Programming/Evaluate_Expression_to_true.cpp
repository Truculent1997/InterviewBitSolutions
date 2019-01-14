long long int modd(long long int x)
{
    return ((x+1003)%1003);
}
int Solution::cnttrue(string A) {
    long long int n=A.length();
    string oper , oprnd;
    long long int ways=0,k=0;
    k=n/2+2;
    long long int T[k+1][k+1],F[k+1][k+1];
    memset(T,0,sizeof(T));
    memset(F,0,sizeof(F));
    k=0;
    for(long long int i=0;i<A.length();i++)
    {
        if(A[i]=='T'||A[i]=='F')oper+=A[i];
        else oprnd+=A[i];
        if(A[i]=='T'){
            T[k][k]=1;
            F[k][k]=0;
            k++;
        }
        if(A[i]=='F'){
            T[k][k]=0;
            F[k][k]=1;
            k++;
        }
    }
    n=k;
    // cout<<k<<" "<<n<<" "<<oper<<" "<<oprnd<<"\n";
    for(long long int gap=1;gap<n;gap++)
    {
        for(long long int i=0;i<n-gap;i++)
        {
            long long int j=gap+i;
            for(long long int k=i;k<j;k++)
            {
                if(oprnd[k]=='|')
                {
                    T[i][j]=modd(T[i][j]+modd(T[i][k]*T[k+1][j]));
                    T[i][j]=modd(T[i][j]+modd(T[i][k]*F[k+1][j]));
                    T[i][j]=modd(T[i][j]+modd(F[i][k]*T[k+1][j]));
                    F[i][j]=modd(F[i][j]+modd(F[i][k]*F[k+1][j]));
                }
                else if(oprnd[k]=='&')
                {
                    T[i][j]=modd(T[i][j]+modd(T[i][k]*T[k+1][j]));
                    F[i][j]=modd(F[i][j]+modd(T[i][k]*F[k+1][j]));
                    F[i][j]=modd(F[i][j]+modd(F[i][k]*T[k+1][j]));
                    F[i][j]=modd(F[i][j]+modd(F[i][k]*F[k+1][j]));
                }
                else if(oprnd[k]=='^')
                {  
                    F[i][j]=modd(F[i][j]+modd(T[i][k]*T[k+1][j]));
                    F[i][j]=modd(F[i][j]+modd(F[i][k]*F[k+1][j]));
                    T[i][j]=modd(T[i][j]+modd(F[i][k]*T[k+1][j]));
                    T[i][j]=modd(T[i][j]+modd(T[i][k]*F[k+1][j]));
                }
            }
        }
    }
    return T[0][n-1];
}
