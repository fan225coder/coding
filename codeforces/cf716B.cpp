
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    string s;
    cin>>s;
    const int n=s.length();
    unordered_set<char> unused;
    for (char ch='A';ch<='Z';ch++) unused.insert(ch);
    int j=-1;
    for (int i=0;i<n;i++) {
        while (j+1<n && (s[j+1]=='?' || unused.count(s[j+1]))) {
            j++;
            if (s[j]!='?') unused.erase(s[j]);
            if (j-i+1==26) {
                for (int ii=i;ii<=j;ii++) {
                    if (s[ii]!='?') continue;
                    auto it=unused.begin();
                    s[ii]=*it;
                    unused.erase(it);
                }
                for (int ii=j+1;ii<n;ii++) {
                    if (s[ii]!='?') continue;
                    s[ii]='A';
                }
                cout<<s;
                return 0;
            }
        }
        if (j==n-1) break;
        if (s[i]=='?') s[i]='A';
        else unused.insert(s[i]);
    }

    cout<<"-1";
    return 0;
}

