#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m, k; cin >> n >> m >> k;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    

    sort(vec.begin(), vec.end());

    vector<ll> diff;

    for (int i=0; i+1<n; i++) {
        diff.push_back(vec[i+1] - vec[i]);
    }

    sort(diff.begin(), diff.end());

    // for (auto &ele : diff) cout << ele << " ";
    // cout << "\n";

    ll sum = accumulate(diff.begin(), diff.begin() + n - k, 0LL);

    sum += k;

    cout << sum << "\n";



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
