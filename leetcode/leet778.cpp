class Solution {
    vector<vector<bool>> visited;

    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};


    bool dfs(int i, int j, const int t, const vector<vector<int>>& a) {
        visited[i][j]=true;
        for (int k=0;k<4;k++) {
            int ii=i+di[k];
            if (ii<0 || ii>=a.size()) continue;
            int jj=j+dj[k];
            if (jj<0 || jj>=a.size()) continue;
            if (a[ii][jj]>t || visited[ii][jj]) continue;
            if (ii==a.size()-1 && jj==a.size()-1) return true;
            if (dfs(ii,jj,t,a)) return true;
        }
        return false;
    }

    public:
    int swimInWater(vector<vector<int>>& a) {
        const int n=a.size();
        auto search=[&](int t) {
            if (a[0][0]>t) return false;
            visited=vector<vector<bool>>(n, vector<bool>(n, false));
            return dfs(0,0,t,a);
        };
        int lo=0,hi=n*n-1;
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            if (search(mid)) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        return lo;
    }
};
