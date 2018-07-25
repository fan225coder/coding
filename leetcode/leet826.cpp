class Solution {
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first>b.first || (a.first==b.first && a.second<b.second);
    }
    public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n=difficulty.size();
        vector<pair<int, int>> jobs;
        jobs.reserve(n);
        for (int i=0;i<n;i++){
            jobs.emplace_back(profit[i], difficulty[i]);
        }

        sort(jobs.begin(), jobs.end(), cmp);
        sort(worker.begin(), worker.end());
        reverse(worker.begin(), worker.end());

        const int m=worker.size();

        int i=0;
        int j=0;

        int p=0;

        while (j<m && i<n) {
            while (i<n && worker[j]<jobs[i].second) i++;
            if (i<n) {
                while (j<m && worker[j]>=jobs[i].second) {
                    p+=jobs[i].first;
                    j++;
                }
            }
        }

        return p;
    }
};
