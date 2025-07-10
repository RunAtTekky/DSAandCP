#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 4e4 + 5;
const int MOD = 1e9 + 7;

vector<ll> palindrome_numbers;

vector<ll> dp;

void precomp() {
    for (int i=1; i<=MAX_N; i++) {
        string curr = to_string(i);

        string rev = curr;
        reverse(rev.begin(), rev.end());

        if (curr == rev) palindrome_numbers.push_back(i);
    }

    dp = vector<ll>(MAX_N);

    dp[0] = 1;

    for (auto &p : palindrome_numbers) {
        for (int i=p; i<MAX_N; i++) {
            dp[i] = (dp[i] + dp[i-p]) % MOD;
        }
    }
}

void solve() {
    ll n; cin >> n;

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomp();
    int t=1; cin >> t;
    while (t--) solve();
}
