int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> m;
    int maxi=0;
    for(int i=0;i<=A.size();i++){
        while(!m.empty()&&(i==A.size()||(A[m.top()]>A[i]))){
            int h=A[m.top()];
            m.pop();
            int w=(m.empty()?i:i-m.top()-1);
            maxi=max(maxi,h*w);
        }
        m.push(i);
    }
    return maxi;
}
