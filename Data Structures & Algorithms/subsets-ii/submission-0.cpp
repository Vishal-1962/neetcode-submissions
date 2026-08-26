class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        getAllSubsets(0,nums,temp,ans);
        return ans;
    }

    void getAllSubsets(int i,vector<int>& arr,vector<int> &temp,vector<vector<int>> &ans){

        if(i == arr.size()){
            ans.push_back(temp);
            return;
        }

        //include
        temp.push_back(arr[i]);
        getAllSubsets(i+1,arr,temp,ans);

        temp.pop_back();//while backtracking

        //excluding
        int idx = i+1;
        while(idx < arr.size() && arr[idx] == arr[idx-1]){
            idx++;
        }
        getAllSubsets(idx,arr,temp,ans);

    }
};