vector<int> Solution::searchRange(const vector<int> &A, int B) {
    if(binary_search(A.begin(),A.end(),B)){
        int low=lower_bound(A.begin(),A.end(),B)-A.begin();
        int upper=upper_bound(A.begin(),A.end(),B)-A.begin()-1;
        return {low,upper};
    }
    return {-1,-1};
}
