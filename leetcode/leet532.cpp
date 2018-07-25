class Solution {
    public:
        int findPairs(vector<int>& numbers, int k) {
            unordered_multiset<int> ms;
            for (auto i:numbers) {
                if (ms.count(i)<2) ms.insert(i);
            }
            unordered_set<int> s(ms.begin(),ms.end());
            if (k==0) return ms.size()-s.size();
            vector<int> a(s.begin(),s.end());
            sort(a.begin(),a.end());
            const int n=a.size();
            int i=0;
            int j=0;
            int count=0;
            while (j<n) {
                while (j+1<n && a[j+1]-a[i]<=k) j++;
                if (i>=j) {
                    i++;
                    j++;
                } else {
                    if (a[j]-a[i]==k) count++;
                    i++;
                }
            }
            return count;
        }
};
