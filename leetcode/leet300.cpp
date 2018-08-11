class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> b;
        b.reserve(a.size());
        auto insert=[&](int x) {
            int lo=0,hi=b.size()-1;
            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                if (b[mid]>=x) {
                    hi=mid;
                } else {
                    lo=mid+1;
                }
            }
            if (lo<b.size() && b[lo]>=x) b[lo]=x;
            else b.push_back(x);
        };
        for (int x:a) {
            insert(x);
        }
        return b.size();
    }
};
