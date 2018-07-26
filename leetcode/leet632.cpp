class Solution {
    void merge(vector<vector<int>>& nums, int& k, vector<int>& a, vector<unordered_set<int>>& lists) {
        k=0;
        int total_size=0;

        priority_queue<pair<int,int>> pq;
        vector<int> cur(nums.size(),0);
        for (int i=0;i<nums.size();i++) {
            if (cur[i]<nums[i].size()) {
                k++;
                pq.emplace(-nums[i][cur[i]],i);
            }
            total_size+=nums[i].size();
        }

        a.reserve(total_size);
        lists.reserve(total_size);
        while (!pq.empty()) {
            int i= -pq.top().first; // (negated) integer
            int l= pq.top().second; // list
            pq.pop();
            cur[l]++;
            if (cur[l]<nums[l].size()) pq.emplace(-nums[l][cur[l]], l);
            if (!a.empty() && a.back()==i) {
                lists.back().insert(l);
            } else {
                a.push_back(i);
                lists.push_back({l});
            }
        }

        //                    for (int i=0;i<a.size();i++) {
        //                        cout<<a[i]<<" {";
        //                        for (auto e:lists[i]) {
        //                            cout<<e<<", ";
        //                        }
        //                        cout<<"}"<<endl;
        //                    }
    }

    public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> a;
        vector<unordered_set<int>> lists;
        int k;
        merge(nums,k,a,lists);

        const int n=a.size();
        int covered=0;
        vector<int> count(k,0);
        int lb=a[0],ub=a.back(); // assert(!a.empty())
        int i=0,j=-1;
        while (i<n) {
            while (j+1<n) {
                for (auto l:lists[j+1]){
                    count[l]++;
                    if (count[l]==1) covered++;
                }
                if (covered==k) {
                    if (a[j+1]-a[i]<ub-lb) {
                        ub=a[j+1];
                        lb=a[i];
                    }
                    for (auto l:lists[j+1]){
                        count[l]--;
                        if (count[l]==0) covered--;
                    }
                    break;
                }
                j++;
            }
            if (j<i) {
                return {a[i],a[i]};
            } else {
                for (auto l:lists[i]){
                    count[l]--;
                    if (count[l]==0) covered--;
                }
                i++;
            }
        }

        return {lb,ub};
    }
};
