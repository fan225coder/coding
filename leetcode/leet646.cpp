class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> end;
        end.reserve(pairs.size());

        sort(pairs.begin(), pairs.end());

        for (const auto& p:pairs) {
            if (!end.empty() && p[1]<end.back()) {
                end.back()=p[1];
            } else if (end.empty() || p[0]>end.back()) {
                end.push_back(p[1]);
            }
        }

        return end.size();
    }
};
