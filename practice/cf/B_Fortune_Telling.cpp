#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, y; cin >> n >> x >> y;

    vector<long long> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    int last_bit = 0;

    for (auto &ele : vec) last_bit = last_bit ^ (ele&1);

    // cout << last_bit << "\n";

    if (x%2 == 0) {
        // This means Alice won't change the bits
        // If last bit and our answer's last bit are same, then Alice
        if (last_bit == (y&1)) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } else {
        // This means that Alice can change the bits
        if (last_bit == (y&1)) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
