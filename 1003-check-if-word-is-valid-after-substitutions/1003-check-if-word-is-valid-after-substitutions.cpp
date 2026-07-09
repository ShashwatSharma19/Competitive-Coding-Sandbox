class Solution {
public:
    bool isValid(string s) {
        int top = -1;
        for(char c:s){
            s[++top] = c;
            if(top >=2 && s[top-2] =='a' && s[top-1] == 'b' && s[top] == 'c'){
                top -= 3;
            }
        }
        return top ==-1;
    }
};