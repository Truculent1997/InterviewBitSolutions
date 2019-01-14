vector<vector<int>> solve(int A,int B,int i,int pick){
     if(pick==B)return vector<vector<int>>();
     vector<vector<int>> ans;
     for(int j=i;B-pick<=A-j+1;j++){
         vector<vector<int>>tmp=solve(A,B,j+1,pick+1);
         if(!tmp.size())ans.push_back({j});
         for(int m=0;m<tmp.size();m++){
             tmp[m].insert(tmp[m].begin(),j);
             ans.push_back(tmp[m]);
         }
     }
     return ans;
}
vector<vector<int> > Solution::combine(int A, int B) {
    return solve(A,B,1,0);
}

