class Solution {
    struct Array {
        int p;
        vector<int>& array;
        Array(vector<int>& a):array(a),p(0){}
        int front() {return array[p];}
        int size() {return array.size()-p;}
        int get(int i) {return array[p+i];}
        int prune(int r) {p+=r; return front();}
    };

    int prune(Array& a, const int k) {
        return a.prune(k);
    }

    int prune(Array& a, Array& b, int k) {
        // assert k is valid
        if (a.size()>b.size()) return prune(b,a,k);
        if (a.size()<=0) return prune(b,k);
        if (k<=0) return min(a.front(),b.front());
        if (k<2) {
            if (a.front()<b.front()) a.prune(1);
            else b.prune(1);
            return prune(a,b,k-1);
        }
        int pa=min(k/2, a.size());
        int pb=min(k/2, b.size());
        int la=a.get(pa-1);
        int lb=b.get(pb-1);
        if (la<=lb) {
            a.prune(pa);
            k-=pa;
        }
        if (la>=lb) {
            b.prune(pb);
            k-=pb;
        }
        return prune(a,b,k);
    }
    public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        Array a(num1);
        Array b(num2);
        int k=(a.size()+b.size()+1)/2-1;
        int first=prune(a,b,k);
        if ((num1.size()+num2.size())%2) return first;
        int second=prune(a,b,1);
        return (first+second)*0.5;

    }
};
