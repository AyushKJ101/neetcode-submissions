class Solution {
public:
    string vec2str(vector<int> num) {
        string s = "";
        for (auto each : num) {
            s += ('0' + each);
        }

        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        queue<vector<int>> q;
        unordered_map<string, int> um;
        um["0000"] = 1;
        for (auto each : deadends) {
            um[each] = -1;
        }

        if (um["0000"] != -1)
            q.push({0,0,0,0});
        int moves = 0;


        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> num = q.front();
                // cout << vec2str(num) << endl;
                if (vec2str(num) == target) return moves;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        vector<int> dummy = num;
                        int dummyi = dummy[i] + (1 * ((j == 0) ? 1 : -1));
                        if (dummyi == 10) dummyi = 0;
                        else if (dummyi == -1) dummyi = 9;

                        dummy[i] = dummyi;
                        string check = vec2str(dummy);
                        if (um.find(check) == um.end()) {
                            um[check] = 1;
                            q.push(dummy);
                        }
                    }
                }
            }
            
            moves++;
        }

        return -1;
    }
};