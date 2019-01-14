vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> m;
    vector<int> res;
    for(int i=0;i<A.size();i++){
        while(!m.empty()&&A[m.back()]<=A[i]){
            m.pop_back();
        }
        m.push_back(i);
        if(i>=B-1){
            if(m.front()<=i-B)m.pop_front();
            res.push_back(A[m.front()]);
        }
    }
    if(B>A.size()){
        res.push_back(A[m.front()]);
    }
    return res;
}
