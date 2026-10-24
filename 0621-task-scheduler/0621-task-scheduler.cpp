class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c: tasks) freq[c-'A']++;

        int maxFreq = 0;
        int countMax = 0;

        for(int f:freq){
            if(f>maxFreq){
                maxFreq = f;
                countMax = 1;
            }else if (f == maxFreq){
                countMax++;
            }
        }

        int partCount = maxFreq-1;
        int partlength = n+1;
        int emptySlot = partCount* partlength;

        int totalSlots = emptySlot+ countMax;

        return max((int)tasks.size(), totalSlots);
    }
};