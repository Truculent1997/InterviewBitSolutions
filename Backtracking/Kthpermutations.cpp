string Solution::getPermutation(int A, int B) {
    vector<int> vec;
    for(int i=1;i<=A;i++){
        vec.push_back(i);
    }
    while(B>1){
        B--;
        next_permutation(vec.begin(),vec.end());
    }
    string str="";
    for(int i=0;i<vec.size();i++){
        str+=to_string(vec[i]);
    }
    return str;
}
