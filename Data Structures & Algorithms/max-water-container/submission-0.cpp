class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0,right=heights.size()-1;
        int Ans=0;
        while(left < right){
            int width = right - left;
            int hght = min(heights[left],heights[right]);
            int area = width * hght;
            Ans = max(Ans,area);
           if(heights[left] < heights[right]){
            left++;
        }else {
            right--;
        }
        }
        return Ans;
    }
};
