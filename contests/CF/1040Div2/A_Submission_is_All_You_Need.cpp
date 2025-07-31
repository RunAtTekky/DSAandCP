#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    ll cnt0 = count(vec.begin(), vec.end(), 0);
    ll cnt1 = count(vec.begin(), vec.end(), 1);

    ll sum = accumulate(vec.begin(), vec.end(), 0LL);

    sum += min(cnt0, cnt1);

    sum += cnt0 - min(cnt0, cnt1);

    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
