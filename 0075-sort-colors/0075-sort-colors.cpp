class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(int n:nums) count[n]++;

        int idx = 0;
        for(int color=0;color<3;color++){
            while(count[color]-- > 0){
                nums[idx++] = color;
            }
        }
    }
};