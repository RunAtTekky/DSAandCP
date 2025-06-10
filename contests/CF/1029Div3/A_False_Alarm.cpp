#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n, x; cin >> n >> x;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    int first = -1, last = -1;

    for (int i=0; i<n; i++) {
        if (first == -1 && vec[i] == 1) first = i;
        else if (first != -1 && vec[i] == 1) last = i;
    }

    if (last-first+1 <= x) {
        YES;
    } else {
        NO;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
