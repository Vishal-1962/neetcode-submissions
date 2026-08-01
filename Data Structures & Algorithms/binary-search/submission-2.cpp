class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        int mid;

        while(st <= end){
            mid = st+(end-st)/2;
            if(target < nums[mid]){
                end = mid-1;
            }else{
                st = mid+1;
            }
            if(target == nums[mid]){
                return mid;
            }
        }
        return -1;
    }
};
