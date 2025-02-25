#include <bits/stdc++.h>
using namespace std;

bool check(int i, bitset<32> target) {
    bitset<32> bits(i);

    // cout << bits.to_string() << "\n";
    // cout << target.to_string() << "\n";

    for (int i=0; i<32; i++) {
        if (target[i] == 0 && bits[i] == 1) {
            return true;
        }
    }

    return false;
}

void solve() {
    int n,x; cin >> n >> x;

    bitset<32> target(x);

    vector<int> key;

    int increase_by = 1;

    int or_val = 0;

    int curr = 0;

    int prev = curr;

    for (int i=0; i<n; i++) {
        bool is_problem = check(curr,target);

        // cout << is_problem << "\n";

        if (!is_problem) {
            or_val |= curr;
            prev = curr;
            key.push_back(curr);
            curr++;
        }
        else {
            curr = prev;
            key.push_back(curr);
        }

        if (key.size() == n) break;
    }

    if (or_val != x) {
        key.pop_back();
        key.push_back(x);
    }

    for (auto &ele : key) cout << ele << " ";
    cout << "\n";
    
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
