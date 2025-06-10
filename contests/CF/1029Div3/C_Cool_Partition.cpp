#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    int ans = 0;

    // map<int,int> prev;
    unordered_set<int> prev;
    prev.insert(vec[0]);
    // prev[vec[0]] = 1;

    for (int i=0, j=0; i<n; i=j) {
        j=i;
        // int sz = prev.size();

        unordered_set<int> new_set;
        // map<int,int> new_set;
        while (j<n && (prev.size() > 0)) {
            // if (prev.count(vec[j])) {
            if (prev.find(vec[j]) != prev.end()) {
                prev.erase(vec[j]);
                // sz--;
            }
            new_set.insert(vec[j]);
            // new_set[vec[j]] = 1;
            j++;
        }

        if (prev.size() == 0) {
            // for (auto &[key, val] : new_set) prev[key] = 1;
            prev = new_set;
            ans++;
        }
    }

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
