#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> max_ahead(n+1);
    vector<ll> min_behind(n+1);

    ll curr = 0;
    for (int i=n-1; i>=0; i--) {
        max_ahead[i] = curr;
        curr = max(curr, vec[i]);
    }

    curr = INT_MAX;
    for (int i=0; i<n; i++) {
        min_behind[i] = curr;
        curr = min(curr, vec[i]);
    }

    for (int i=0; i<n; i++) {
        if (min_behind[i] < vec[i] && max_ahead[i] > vec[i]) {
            cout << "0";
        } else {
            cout << "1";
        }
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
