class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;

        getCombination(0,nums,target,ans,ds);
        return ans;
    }

    void getCombination(int i,vector<int>& arr,int target,vector<vector<int>> &ans,vector<int> &ds){
        if(i == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return ;
        }

        if(arr[i] <= target){
            ds.push_back(arr[i]);
            getCombination(i,arr,target-arr[i],ans,ds);
            ds.pop_back();
        }
        getCombination(i+1,arr,target,ans,ds);
    }
};
