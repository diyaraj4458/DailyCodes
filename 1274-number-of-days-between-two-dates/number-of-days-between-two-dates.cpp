class Solution {
public:
    bool ly(int& y){
        return (y % 4 == 0 && y % 100 != 0) || y % 400== 0;
    }

    int dis(string& date){
        int y = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + date[3]-'0';
        int m = (date[5]-'0')*10 + date[6]-'0';
        int d = (date[8]-'0')*10 + date[9]-'0';

        array<int,12> arr = {31,28,31,30,31,30,31,31,30,31,30,31};
        int days{};

        for(int i = 1971; i < y; ++i)
            days += 365 + ly(i);

        for(int i = 0; i < m-1; ++i)
            days += arr[i];

        days += d;

        if(m > 2 && ly(y)) ++days;
        return days;
    }
    int daysBetweenDates(string& date1, string& date2) {
        return abs(dis(date1)-dis(date2));   
    }
};