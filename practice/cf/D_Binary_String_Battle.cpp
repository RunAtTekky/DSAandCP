#include <bits/stdc++.h>
using namespace std;

#define ALICE cout << "Alice\n"
#define BOB cout << "Bob\n"  

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;

    string s; cin >> s;

    ll ones = count(s.begin(), s.end(), '1');

    if (ones <= k) {
        ALICE; return;
    }

    vector<ll> idxs;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') idxs.push_back(i);
    }

    ll threat = 0;
    for (int i=0; i<idxs.size(); i++) {
        ll ahead = n-idxs[i]-1;
        ll behind = idxs[i];

        if (max(ahead, behind) >= k) {
            threat++;
        }
    }

    if (threat > k) {BOB; return;}

    ALICE;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
