class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        if (s.size() != t.size()) return false;
        for(char x : s){
            mp1[x]++;
        }
        for(char y : t){
            mp2[y]++;
        }
        for(char a : s){
            if(mp1[a] != mp2[a]) return false;
        }
        return true;
    }
};
