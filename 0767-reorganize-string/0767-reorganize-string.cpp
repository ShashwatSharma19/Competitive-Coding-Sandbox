#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int maxFreq = 0, maxChar = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        
        if (maxFreq > (n + 1) / 2) return "";

        string result(n, ' ');
        int idx = 0;

       
        while (freq[maxChar] > 0) {
            result[idx] = 'a' + maxChar;
            idx += 2;
            freq[maxChar]--;
            if (idx >= n) idx = 1;  
        }

        
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (idx >= n) idx = 1;
                result[idx] = 'a' + i;
                idx += 2;
                freq[i]--;
            }
        }

        return result;
    }
};