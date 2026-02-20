class Solution {
public:
    string makeLargestSpecial(string s) {
        int curr = 0;
        vector<string> spec;
        for(int i = 0, j = 0, n = s.length(); j < n; ++j){
            curr += (s[j] == '1') ? 1 : -1;
            if(curr == 0){
                spec.push_back('1' + makeLargestSpecial(s.substr(i + 1 , j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(spec.begin() , spec.end() , greater<>());
        string res;
        for(int i = 0, m = spec.size(); i < m; ++i) res += spec[i];
        return res; 
    }
};