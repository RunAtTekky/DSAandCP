#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;
    string s; cin >> s;

    long long count_dash = count(s.begin(), s.end(), '-');
    long long count_underscore = count(s.begin(), s.end(), '_');

    long long lft_side = count_dash / 2;
    long long rgt_side = count_dash - lft_side;

    long long answer = lft_side * count_underscore * rgt_side;

    cout << answer << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
