class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        for (auto each : s) {
            if (each == '1') one++;
        }

        string o = "";
        for (int i = 0; i < s.size() - 1; i++) {
            if (one > 1) {
                o = o + "1";
                one--;
            }

            else o = o + "0";
        }

        if (one == 1) o = o + '1'; else o = o + '0';

        return o;
    }
};