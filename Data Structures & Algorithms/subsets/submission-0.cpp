class Solution {
public:
    
    void getSubset(int i,vector<int>& arr,vector<int> &temp,vector<vector<int>> &ans){

        if(i == arr.size()){
            ans.push_back({temp});
            return;
        }
        //include
        temp.push_back(arr[i]);
        getSubset(i+1,arr,temp,ans);

        temp.pop_back(); //while backtracking remove element

        //excluding 
        getSubset(i+1,arr,temp,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;

        getSubset(0,nums,temp,ans);

        return ans;
    }
};
