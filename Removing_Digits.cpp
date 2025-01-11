#include <bits/stdc++.h>
using namespace std;

vector<int> get_digits(int x) {
    vector<int> digits;

    string x_string = to_string(x);

    for (auto ch : x_string) {
        digits.push_back(ch-'0');
    }

    return digits;
}

void solve() {
    int n; cin >> n;

    vector<long long> dp(n+1);

    // dp[i] = 1 + min( dp[i-digits[j]] ), digits[j] = {digits of i}

    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        vector<int> digits = get_digits(i);

        long long minimum_steps_to_make_zero = INT_MAX;
        for (auto digit : digits) {
            if (digit == 0) continue;
            minimum_steps_to_make_zero = min(minimum_steps_to_make_zero, dp[i-digit]);
        }
        dp[i] = 1 + minimum_steps_to_make_zero;
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
