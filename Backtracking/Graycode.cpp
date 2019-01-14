vector<int> Solution::grayCode(int A) {
    vector<int>ans;
    for(int i=0;i<pow(2,A);i++){
        int j=i;
        int g=0;
        int c=0;
        while(j){
           int x=((j&2)>0?1:0);
           x^=(j&1);
           g|=x<<c;
           c++;
           j=j>>1;
        }
        //cout<<g<<endl;
        ans.push_back(g);
    }
    return ans;
}
