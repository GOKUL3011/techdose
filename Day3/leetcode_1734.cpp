class Solution {
public:
    vector<int> decode(vector<int>& v) {
        int x = 0;
        for(auto &i: v)
            x = (x^i);
        vector<int> tmp = v;
        for(int i = 1; i < v.size(); i++){
            tmp[i] = (tmp[i-1]^v[i]);
        }
        for(int i = 1; i<= v.size()+1; i++){
            if(i <= v.size()){
                x = (x^tmp[i-1]);
            }
            x ^= i;
        }
        vector<int> ans = {x};
        for(int i = v.size()-1; i>= 0; i--){
            ans.push_back(ans.back()^v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
