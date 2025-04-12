#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                ll comp = (ll)target - (nums[i] + nums[j]);
                int k = j + 1, l = n - 1;
                while (k < l) {
                    if (nums[k] + nums[l] == comp) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;
                        k++;
                        l--;
                    } else if (nums[k] + nums[l] > comp) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};