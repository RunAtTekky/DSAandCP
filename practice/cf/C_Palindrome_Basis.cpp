#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
const int MOD = 1e9 + 7;

// vector<int> palindromes;
unordered_set<int> palindromes;

unordered_map<int,pair<int,int>> dp;

bool is_pal(int x) {
    string str = to_string(x);

    string rev = str;
    reverse(rev.begin(), rev.end());

    return str == rev;
}

void precomp() {
    for (int i=1; i<=N; i++) {
        if(is_pal(i)) {
            palindromes.insert(i);
        }
    }

    for (int i=1; i<N; i++) {
        int extras = 0;
        dp[i].first += dp[i-1].first;
        for (int j=i-2; j>=0; j--) {
            if (j + j < i) break;
            if (palindromes.count(i-j)) extras += dp[j].second;
        }

        if (palindromes.count(i)) {
            extras++;
        }

        dp[i].first += extras;
        dp[i].second = extras;

        cout << i << " " << dp[i].first << " " << dp[i].second << "\n";
    }
}

void solve() {
    ll n; cin >> n;

    cout << dp[n].first << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomp();
    int t=1; cin >> t;
    while (t--) solve();
}
