class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixcount;
        prefixcount[0] = 1;

        int prefixSum=0, count=0;
        for(int num:nums){
            prefixSum += num;
            int target = prefixSum-k;
            if(prefixcount.find(target) != prefixcount.end()){
                count+=prefixcount[target];
            }
            prefixcount[prefixSum]++;
        }
        return count;
    }
};