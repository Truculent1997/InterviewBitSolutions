https://www.interviewbit.com/problems/largest-coprime-divisor/


int Solution::cpFact(int A, int B) {
    int x=A/__gcd(A,B);
    while(__gcd(x,B)!=1)x/=__gcd(x,B);
    return x;
}
