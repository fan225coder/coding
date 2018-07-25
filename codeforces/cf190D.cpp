#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

uint64_t lt;
uint64_t n, k;
vector<int> a;

unordered_map<int, int> count;

int main() {
    cin>>n>>k;
    a=vector<int>(n);
    for (int i=0;i<n;i++) cin>>a[i];
    lt = 0;

    int i=0;
    int j=-1;

    while (i<n) {
        while (j+1<n) {
            int nxt=a[j+1];
            if (!count.count(nxt)) count[nxt]=0;
            count[nxt]++;
            if (count[nxt]>=k) {
                count[nxt]--; // erase if 0 ??
                break;
            }
            j++;
        }
        if (j<i) {
            i++;j++;
        } else {
            const int64_t d=j-i+1;
            if (j==n-1) {
                lt+= d%2 ? (d+1)/2*d : d/2*(d+1);
                break;
            } else {
                lt+=d;
            }
            count[a[i]]--; // erase if 0 ?
            i++;
        }
    }

    cout<<(n%2?(n+1)/2*n:n/2*(n+1))-lt;
    return 0;
}
