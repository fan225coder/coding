class Solution {
    int two_pointer(const vector<int>& a) {
        const int n = a.size();
        int len=0;
        bool flipped = false;
        int j = -1;
        for (int i=0;i<n;i++) {
            while (j+1<n) {
                if (a[j+1]==0 && flipped) {
                    len=max(len, j-i+1);
                    break;
                }
                if (a[j+1]==0) flipped=true;
                j++;
            }
            if (j==n-1) return max(len, j-i+1);
            if (a[i]==0) flipped=false;
        }
        return len;
    }

    int stream(const vector<int>& a) {
        if (a.empty()) return 0;
        array<int,2> f({-1,-1});
        int i=0;
        int len=0;

        for (int x:a) {
            if (x) {
                if (f[0]==-1) f[0]=i;
            }else {
                if (f[1]==-1) {
                    f[1]=f[0]!=-1?f[0]:i;
                } else {
                    len=max(len, i-f[1]);
                    f[1]=f[0];
                }
                f[0]=-1;
            }
            cout<<f[0]<<" "<<f[1]<<endl;
            i++;
        }
        if (f[0]!=-1) len=max(len, i-f[0]);
        if (f[1]!=-1) len=max(len, i-f[1]);
        return len;
    }
    public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        //return two_pointer(a);
        return stream(a);

    }
};
