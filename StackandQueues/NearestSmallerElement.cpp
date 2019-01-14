vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> m;
    int n=A.size();
    vector<int> ans(n,-1);
    m.push(n-1);
    for(int i=A.size()-2;i>=0;i--){
        while(!m.empty()&&A[m.top()>A[i]]){
            cout<<m.top()<<endl;
            ans[m.top()]=A[i];
            m.pop();
        }
        m.push(i);
    }
    return ans;
}
