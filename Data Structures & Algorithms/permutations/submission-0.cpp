class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        backtrack(nums, 0, res);

        return res;
    }

    void backtrack(vector<int>& nums, int start,
                   vector<vector<int>>& res) {

        // We have formed one complete permutation
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        // Try every number at the current position
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);

            backtrack(nums, start + 1, res);

            // Undo the swap (backtrack)
            swap(nums[start], nums[i]);
        }
    }
};