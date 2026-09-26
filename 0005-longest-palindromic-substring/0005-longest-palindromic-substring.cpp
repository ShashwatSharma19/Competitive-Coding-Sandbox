class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start=0, maxlen=1;

        for(int i=0; i<s.size();i++){
            expand(s,i,i,start, maxlen);
            expand(s,i,i+1,start, maxlen);
        }
        return s.substr(start, maxlen);
    }

private:
void expand(const string& s, int left, int right, int& start, int& maxlen){
    while(left >=0 && right<s.size() && s[left] == s[right]){
        left--;
        right++;
    }

    int len = right-left-1;
    if(len>maxlen){
        maxlen = len;
        start = left+1;
    }
}
};