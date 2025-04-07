class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest{INT_MAX}, sum{0}, tsum{0};
        int i{0},j{0}, n = nums.size(), k =n;
        for(int i=0;i<n;i++){
            j=i+1;
            k = n-1;
            while(j<n && k>=0 && j<k){
                tsum = nums[i]+nums[j]+nums[k];
                if(abs(target-tsum) < closest){
                    sum = tsum;
                    closest = abs(target-tsum);
                }
                if(tsum>target)
                    k--;
                else 
                    j++;

            }
        }
        return sum;
    }
};