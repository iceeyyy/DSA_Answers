class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for(int hr=0;hr<12;hr++){
            for(int mm=0;mm<60;mm++){
                if(__builtin_popcount(hr)+__builtin_popcount(mm)==turnedOn){
                    string hour = to_string(hr);
                    string minute = (mm<10?"0":"")+to_string(mm);
                    res.push_back(hour+":"+minute);
                }
            }
        }
        return res;
    }
};