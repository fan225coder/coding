class Solution {
    int binary_search(const vector<vector<int>>& a, int target, int il, int ih, int jl, int jh) {
        int lo=0;
        int hi=min(ih-il, jh-jl);
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            if (a[il+mid][jl+mid]>=target) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        return lo;
    };

    bool divide_and_conquer(const vector<vector<int>>& a, int target, int il, int ih, int jl, int jh){
        if (il>ih || jl>jh) return false;
        int d=binary_search(a,target, il,ih,jl,jh);
        int i=il+d;
        int j=jl+d;
        if (a[i][j]==target) return true;
        if (a[i][j]<target) {
            i++;
            j++;
        }
        if (divide_and_conquer(a, target, i, ih, jl, j-1)) return true;
        if (divide_and_conquer(a, target, il, i-1, j, jh)) return true;
        return false;
    };

    bool two_pointer(const vector<vector<int>>& a, int target) {
        const int m=a[0].size();
        int j=-1;
        for (int i=a.size()-1;i>=0;i--) {
            while (j+1<m && a[i][j+1]<target) {
                j++;
            }
            if (j+1<m && a[i][j+1]==target) return true;
        }
        return false;
    }

    public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        if (a.empty()) return false;
        return two_pointer(a,target);
    }
};
