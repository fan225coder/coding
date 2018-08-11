class Solution {
    int dp(const vector<int>& a) {
        const int n=a.size();
        vector<int> count(n, 1);
        vector<int> len(n, 1);

        int max_len=0;

        for (int i=0;i<n;i++) {
            for (int j=0;j<i;j++) {
                if (a[j]>=a[i]) continue;
                if (len[j]+1<len[i]) continue;
                if (len[j]+1==len[i]) {
                    count[i]+=count[j];
                } else {
                    len[i]=len[j]+1;
                    count[i]=count[j];
                }
            }
            max_len=max(max_len, len[i]);
        }
        int total=0;
        for (int i=0;i<n;i++) {
            if (len[i]==max_len) total+=count[i];
        }
        return total;
    }

    int nlogn(const vector<int>& a) {
        if (a.empty()) return 0;
        const int MIN=numeric_limits<int>::min();
        const int MAX=numeric_limits<int>::max();
        struct Info {
            int value, count, prefix_sum;
            Info(int value, int count=0, int prefix_sum=0) :value(value),count(count),prefix_sum(prefix_sum) {}
        };
        vector<vector<Info>> info;

        info.push_back({Info(MAX), Info(MIN,1,1)});

        auto col=[&](int x) {
            int lo=0, hi=info.size()-1;
            while (lo<hi) {
                int mid=lo+(hi-lo+1)/2;
                if (info[mid].back().value>=x) {
                    hi=mid-1;
                } else {
                    lo=mid;
                }
            }
            return lo;
        };

        auto row=[&](int c, int x) {
            int lo=0, hi=info[c].size()-1;
            while (lo<hi) {
                int mid=lo+(hi-lo+1)/2;
                if (info[c][mid].value<x) {
                    hi=mid-1;
                } else {
                    lo=mid;
                }
            }
            return lo;
        };

        auto update=[&](int x) {
            //printf("x=%d\n",x);
            int c=col(x);
            int r=row(c,x);

            auto print=[&]() {
                for (int i=0;i<info.size();i++) {
                    if (i==c) printf("*");
                    else printf(" ");
                    for (int j=0;j<info[i].size();j++) {
                        int v=info[i][j].value;
                        if (v==MIN) printf("-");
                        else if (v==MAX) printf("+");
                        else printf("%d", v);
                        if (i==c && j==r) printf("* ");
                        else printf(" ");
                    }
                    printf("\n");
                }
            };

            int count=info[c].back().prefix_sum - info[c][r].prefix_sum;
            if (c==info.size()-1) {
                info.push_back({Info(MAX), Info(x,count,count)});
            } else {
                int prefix_sum=count+info[c+1].back().prefix_sum;
                info[c+1].push_back(Info(x,count,prefix_sum));
            }

            //print();

        };




        for (const int x:a) update(x);
        return info.back().back().prefix_sum;
    }

    public:
    int findNumberOfLIS(vector<int>& a) {
        return nlogn(a);
    }
};
