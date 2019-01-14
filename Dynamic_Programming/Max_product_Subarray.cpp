int Solution::maxProduct(const vector<int> &A) {
    bool f=false;
    int ff=0,ss=0;
    int ans=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i]>0){
            if(!ff)ff=1;
            ff*=A[i];
            ans=max(ans,ff);
            //cout<<"f:"<<f<<"  "<<A[i]<<"   "<<ss<<endl;
            if(f)ss*=A[i];
            ans=max(ans,ss);
        }
        else if(A[i]<0){
            if(!ff)ff=1;
            if(f)ss*=A[i];
            ans=max(ans,ss);
            if(!f){f=true;ss=1;}
            ff*=A[i];
            ans=max(ans,ff);
        }
        else{
            ff=0;
            ss=0;
            f=false;
            ans=max(0,ans);
        }
        //cout<<ff<<"   "<<ss<<endl;
    }
    return ans;
}
