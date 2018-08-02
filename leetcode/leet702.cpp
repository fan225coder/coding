// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        const int out=2147483647;
        int lo=0,hi=20000;
        while (lo<hi) {
            int mid=lo+(hi-lo+1)/2;
            int x=reader.get(mid);
            if (x==out) {
                hi=mid-1;
            } else {
                lo=mid;
            }
        }
        if (reader.get(lo)==out) return -1;
        hi=lo;
        lo=0;
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            int x=reader.get(mid);
            if (x<target) {
                lo=mid+1;
            } else if (x>target) {
                hi=mid-1;
            } else {
                return mid;
            }
        }
        if (reader.get(lo)==target) return lo; // be careful

        return -1;
    }
};
