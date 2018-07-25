/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        vector<int> findRightInterval(vector<Interval>& intervals) {
            const int n=intervals.size();
            vector<pair<int,int>> start_index;
            for (int i=0;i<n;i++) {
                start_index.emplace_back(intervals[i].start, i);
            }
            sort(start_index.begin(),start_index.end());
            vector<int> right;
            right.reserve(n);
            for (auto i:intervals) {
                int hi=n-1;
                int lo=0;
                while (lo<hi) {
                    int mid=lo+(hi-lo)/2;
                    if (i.end<=start_index[mid].first) {
                        hi=mid;
                    } else {
                        lo=mid+1;
                    }
                }
                if (start_index[lo].first>=i.end) {
                    right.push_back(start_index[lo].second);
                } else {
                    right.push_back(-1);
                }
            }
            return right;

        }
};
