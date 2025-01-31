#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;

    int count_one = count(s.begin(), s.end(), '1');

    cout << count_one << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
