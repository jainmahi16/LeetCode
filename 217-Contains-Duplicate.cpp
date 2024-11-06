class Solution {
public:
    bool containsDuplicate(vector<int>& arr) { 
        unordered_set<int> uniqueElements;

        for (const int val : arr) {
            if (!uniqueElements.insert(val).second) {
                return true;
            }
        }
        return false;
    }
};
