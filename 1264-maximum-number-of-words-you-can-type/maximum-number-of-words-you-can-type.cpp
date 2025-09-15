class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char c : brokenLetters) {
            broken.insert(c);
        }
        
        int ans = 0;
        bool hasBroken = false;
        
        for (int i = 0; i < text.size(); i++) {
            if (broken.count(text[i]) > 0) {
                hasBroken = true;
            }
            if (text[i] == ' ' || i == text.size() - 1) {
                if (!hasBroken) {
                    ans++;
                }
                hasBroken = false;
            }
        }
        
        return ans;
    }
};