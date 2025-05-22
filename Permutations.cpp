class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    void solve(vector<int>& nums, vector<int>& temp, int idx){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            temp.push_back(nums[i]);
            solve(nums, temp, idx+1);
            st.erase(nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp, 0);
        return ans;    
    }
};