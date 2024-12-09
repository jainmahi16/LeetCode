class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size(); 
        for (int& num : nums) {
            int index = abs(num) - 1; 

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        vector<int> result;
        for (int i = 0; i < size; ++i) {
    
            if (nums[i] > 0) {
                result.push_back(i + 1); 
            }
        }  
        return result; 
    }
};
