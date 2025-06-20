#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s; cin >> n >> s;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    int lft = abs(s - vec.front());
    int rgt = abs(s - vec.back());

    cout << min(lft,rgt) + (vec.back() - vec.front()) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
