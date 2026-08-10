class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(int x : nums){
            mpp[x]++;
            if(mpp[x] > 1){
                return x;
            }
        }
        return -1;
    }
};
