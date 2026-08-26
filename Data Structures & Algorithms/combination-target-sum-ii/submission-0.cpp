class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        // 1. Sort to easily handle duplicates
        sort(candidates.begin(), candidates.end()); 
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }

private:
    void findCombination(int indx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        // Base case: if target is met, record the combination
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = indx; i < arr.size(); i++) {
            // 2. Skip duplicates at the same recursive level
            if (i > indx && arr[i] == arr[i - 1]) continue; 
            
            // 3. Optimization: break early if the element exceeds remaining target
            if (arr[i] > target) break; 

            // Include the element
            ds.push_back(arr[i]);
            // Move to the next index (i + 1) with reduced target
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            // Backtrack
            ds.pop_back();
        }
    }
};
