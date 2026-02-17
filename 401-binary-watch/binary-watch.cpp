class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int hh=0;hh<=11;hh++){
            for(int mm=0;mm<=59;mm++){
                if(__builtin_popcount(hh)+__builtin_popcount(mm)==turnedOn){
                    string hour=to_string(hh);
                    string minute=(mm<10? "0"+to_string(mm):to_string(mm));
                    result.push_back(hour+":"+minute);
                }
            }
        }
        return result;
    }
};