#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    ll mini = vec.front();
    for (int i=1; i<n; i++) {
        if (vec[i] < mini) {
            mini = min(mini, vec[i]); continue;
        }
        if (vec[i] >= 2 * mini) {NO; return;}
        mini = min(mini, vec[i]);
    }

    YES;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
