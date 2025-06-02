class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        // Trim trailing spaces
        int end = s.length() - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        // Find the start of the last word
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        // The length of the last word is (end - start)
        return end - start;
    }
};
