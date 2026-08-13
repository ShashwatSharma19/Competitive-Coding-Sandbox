class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n+1,0);
        for(int i=0;i<=n;i++){
        int left = max(0, i-ranges[i]);
        int right = min(n,i+ranges[i]);
        maxReach[left] = max(maxReach[left], right);
        }

        int taps=0, currentEnd=0,farthest=0, i=0;
        while(currentEnd < n){
            while(i <= currentEnd){
            farthest = max(farthest, maxReach[i]);
            i++;
            }
            if(farthest <= currentEnd) return -1;
            taps++;
            currentEnd = farthest;
        }
        return taps;
    }
};