#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int max_length = 1; // Maximum length of repetition
    int current_length = 1; // Current length of consecutive characters
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            current_length++; // Increment if current char matches previous
            max_length = max(max_length, current_length); // Update max if needed
        } else {
            current_length = 1; // Reset count if different char
        }
    }
    cout << max_length << endl;
    return 0;
}