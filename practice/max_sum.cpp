#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n,k; cin >> n >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    map<ll, ll> sum;

    for (auto &ele : vec) {
        sum[ele] += max(0, ele);
    }

    vector<ll> sums;
    for (auto &[ele,s] : sum) sums.push_back(s);

    sort(sums.begin(), sums.end());

    cout << accumulate(sums.begin() + sums.size() - k, sums.end(), 0LL) << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
