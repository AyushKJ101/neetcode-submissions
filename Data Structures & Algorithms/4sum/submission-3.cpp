class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        unordered_map<long long, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }

        vector<vector<int>> out;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    long long left = 1LL * target - nums[i] - nums[j] - nums[k];
                    if (um.find(left) != um.end() && um[left] > k) {
                        vector<int> dummy = {nums[i], nums[j], nums[k], (int)left};
                        int flag = 1;
                        for (auto each : out) {
                            if (each[0] == nums[i] &&
                                each[1] == nums[j] &&
                                each[2] == nums[k]
                            ) {
                                flag = 0;
                                break;
                            }
                        }

                        if (flag) out.push_back(dummy);
                    }
                }
            }
        }

        return out;
    }
};