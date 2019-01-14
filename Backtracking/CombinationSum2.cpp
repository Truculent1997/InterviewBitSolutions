vector<vector<int>> solve(vector<int> A,int i,int B,int sum){
    if(sum>B||A.size()==i)return {};
    vector<vector<int>> ans;
    for(int j=i;j<A.size();j++){
        if(sum+A[j]==B)ans.push_back({A[j]});
        if(sum+A[j]<B&&j<A.size()-1){
            vector<vector<int>> tmp=solve(A,j+1,B,sum+A[j]); 
            for(int m=0;m<tmp.size();m++){
                tmp[m].insert(tmp[m].begin(),A[j]);
                ans.push_back(tmp[m]);
            }
        }
    }
    return ans;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    map<vector<int>,bool> my;
    vector<vector<int>> ans=solve(A,0,B,0);
    vector<vector<int>> res;
    for(auto i:ans){
        if(my.find(i)==my.end()){
            res.push_back(i);
            my[i]=true;
        }
    }
    return res;
}
