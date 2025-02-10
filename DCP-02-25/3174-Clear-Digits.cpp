class Solution {
public:
    std::string clearDigits(const std::string& s) {
        std::string om;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                if (!om.empty()) {
                    om.pop_back(); // Remove the last character if om is not empty
                }
            } else {
                om.push_back(c); // Append the character if it's not a digit
            }
        }
        return om;
    }
};