class Solution {
    uniform_int_distribution<int> dist;
    random_device rd;
    mt19937 mt;

    vector<int> a;
    public:
    Solution(vector<int> weights) {
        a.reserve(weights.size());
        int sum=0;
        for (int w:weights) {
            a.push_back(sum);
            cout<<sum<<" ";
            sum+=w;
        }
        cout<<endl;
        dist=uniform_int_distribution<int>(0,sum-1);
        mt=mt19937(rd());
    }

    int pickIndex() {
        int t=dist(mt);
        int lo=0,hi=a.size()-1;
        while (lo<hi) {
            int mid=lo+(hi-lo+1)/2;
            if (t<a[mid]) {
                hi=mid-1;
            }else {
                lo=mid;
            }
        }
        cout<<t<<" "<<lo<<endl;
        return lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
