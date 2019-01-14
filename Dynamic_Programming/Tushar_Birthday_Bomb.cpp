vector<int> Solution::solve(int A, vector<int> &B) {
    int mini=INT_MAX;
    int ind=-1;
    for(int i=0;i<B.size();i++){
        if(mini>B[i]){
            mini=B[i];
            ind=i;
        }
    }
    vector<int> lol;
    int rem=A%mini;
    int ans=A/mini;
    //cout<<rem<<"  "<<ans<<endl;
    int c=0;
    for(int i=0;i<ind;i++){
        while(ans&&rem-B[i]+mini>=0){
            lol.push_back(i);
            rem=rem-B[i]+mini;
            ans--;
            if(rem<=0)break;
        }
    }
    while(c<ans){
        lol.push_back(ind);
        c++;
    } 
    return lol;
}
