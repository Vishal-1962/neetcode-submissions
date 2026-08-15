class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (string& str : strs) {
            ans += to_string(str.size()) + "#" + str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Start of actual string
            j++;

            // Extract exactly len characters
            ans.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};