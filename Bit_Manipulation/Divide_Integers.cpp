int Solution::divide(int A, int B) {
      long long int a=A;
      long long int b=B;
      bool f=false;
      if((a>=0&&b>=0)||(a<0&&b<0))f=true;
      if(a<0)a=a*-1;
      if(b<0)b=b*-1;
      long long int c=0;
      while(a>=b){
          long long int x=b;
          long long int w=-1;
          while(a>=x){
             w++;
             x=x<<1; 
          }
          a-=(x>>1);
          c+=(1LL<<w);
      }
      if(!f)c=c*-1;
      if(INT_MAX>=c&&INT_MIN<=c)return c;
      else return INT_MAX;
}
