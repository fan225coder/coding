class Solution {
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        }
    };
    public:
    int maxEnvelopes(vector<pair<int, int>>& e) {
        sort(e.begin(), e.end(), cmp());
        vector<int> b;
        b.reserve(e.size());

        auto insert=[&](int x) {
            int lo=0,hi=b.size()-1;
            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                if (x<=b[mid]) {
                    hi=mid;
                } else {
                    lo=mid+1;
                }
            }
            if (lo<b.size() && b[lo]>=x) {
                b[lo]=x;
            } else {
                b.push_back(x);
            }
        };

        for (auto x:e) insert(x.second);

        return b.size();


    }
};
