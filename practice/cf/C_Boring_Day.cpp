#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, l, r; cin >> n >> l >> r;

    vector<int> cards(n);
    for (auto &card : cards) cin >> card;

    long long sum = 0;
    long long rounds_won = 0;

    vector<long long> prefix(n+1);

    for (int i=1; i<=n; i++) {
        prefix[i] = prefix[i-1] + cards[i-1];
    }

    // for (auto &ele : prefix) cout << ele << " ";
    // cout << "\n";

    vector<long long> wins_at_this_point(n+1);

    for (int i=0; i<=n; i++) {
        rounds_won = max(rounds_won, wins_at_this_point[i]);

        long long lower = prefix[i] + l;
        long long upper = prefix[i] + r;

        int startIndex = lower_bound(prefix.begin(), prefix.end(), lower) - prefix.begin();

        if (startIndex<=n && prefix[startIndex] <= upper) {
            wins_at_this_point[startIndex] = max(wins_at_this_point[startIndex], rounds_won+1);
        }
    }

    cout << rounds_won << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
