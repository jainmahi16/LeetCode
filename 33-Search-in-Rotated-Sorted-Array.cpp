class Solution {
public:
    int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size - 1;
    while (left < right) {
    int mid = left + (right - left) / 2; 
    if (nums[0] <= nums[mid]) {
    if (nums[0] <= target && target <= nums[mid]) {
    right = mid;
    } 
    else {
            left = mid + 1;
         }
    } 
    else {
                
    if (nums[mid] < target && target <= nums[size - 1]) {
                    
     left = mid + 1;
    }
     else {
           right = mid;
          }
     }
    }
    return (left == right && nums[left] == target) ? left : -1;
    }
};