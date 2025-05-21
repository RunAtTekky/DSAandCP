#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    if (count(vec.begin(), vec.end(), 1) == n) {YES; return;}
    
    for (int i=0; i+1<n; i++) {
        if (vec[i] == 0 && vec[i] == vec[i+1]) {
            YES; return;
        }
    }
    NO;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
