vector<vector<int>> solve(vector<int> A,int i,int B,int sum){
    if(sum>B||A.size()==i)return {};
    vector<vector<int>> ans;
    for(int j=i;j<A.size();j++){
        if(sum+A[j]==B)ans.push_back({A[j]});
        if(sum+A[j]<B&&j<A.size()){
            vector<vector<int>> tmp=solve(A,j,B,sum+A[j]); 
            for(int m=0;m<tmp.size();m++){
                tmp[m].insert(tmp[m].begin(),A[j]);
                ans.push_back(tmp[m]);
            }
        }
    }
    return ans;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    map<int,int> m;
    vector<int> AA;
    for(int i=0;i<A.size();i++){
        if(m.find(A[i])==m.end()){
            AA.push_back(A[i]);
            m[A[i]]=1;
        }
    }
    sort(AA.begin(),AA.end());
    return solve(AA,0,B,0);
    //sort(ans.begin(),ans.end());
    //return ans;
}
