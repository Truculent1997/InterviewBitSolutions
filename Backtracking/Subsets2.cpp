vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    long long int l=pow(2,n);
    for(int i=0;i<l;i++){
        vector<int> temp;
        int j=i;
        int c=0;
        while(j){
            if(j&1)temp.push_back(A[c]);
            j=j>>1;
            c++;
        }
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    map<vector<int>,bool> my;
    vector<vector<int>> res;
    for(auto i:ans){
        if(my.find(i)==my.end()){
            res.push_back(i);
            my[i]=true;
        }
    }    
    return res ;
}

