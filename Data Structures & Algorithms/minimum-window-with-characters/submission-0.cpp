class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        // Frequency table for target string t
        vector<int> targetFreq(128, 0);
        int required = 0;
        for (char c : t) {
            if (targetFreq[c] == 0) required++; // Count unique chars in t
            targetFreq[c]++;
        }

        // Frequency table for current window in s
        vector<int> windowFreq(128, 0);
        int formed = 0; // Number of unique chars satisfying target frequency

        int left = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            windowFreq[c]++;

            // Check if adding c fulfills target requirement for this character
            if (targetFreq[c] > 0 && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Shrink window from the left while it contains all required characters
            while (left <= right && formed == required) {
                // Update minimum length and start index
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                // Remove left character from window
                char leftChar = s[left];
                windowFreq[leftChar]--;

                // If leftChar was vital, decrement formed
                if (targetFreq[leftChar] > 0 && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};