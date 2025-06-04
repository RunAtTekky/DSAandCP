#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int,int> freq;
ll n, m; 
vector<ll> vec;

bool ok(int mid) {
    ll extra = 0;
    for (int i=1; i<=n; i++) {
        int fr = freq[i];
        if (fr >= mid) extra += fr - mid;
        else extra -= (mid - fr) / 2;
    }

    // if (extra <= 0) cout << mid << " passed\n";
    return extra <= 0;
}



void solve() {
    cin >> n >> m;

    vec = vector<ll>(m);
    for (auto &ele : vec) cin >> ele;

    freq.clear();
    for (auto &ele : vec) freq[ele]++;

    ll start = 1, end = INT_MAX;
    while (start <= end) {

        ll mid = (start + end) / 2;

        if (ok(mid)) end = mid - 1;
        else start = mid + 1;
    }

    cout << start << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
