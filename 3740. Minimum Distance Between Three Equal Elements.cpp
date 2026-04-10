#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : mp) {
            vector<int> v = it.second;

            if (v.size() < 3) continue;

            for (int i = 0; i + 2 < v.size(); i++) {
                int i1 = v[i];
                int i3 = v[i + 2];

                int dist = 2 * (i3 - i1);

                ans = min(ans, dist);
            }
        }

        if (ans == INT_MAX) return -1;

        return ans;
    }
};