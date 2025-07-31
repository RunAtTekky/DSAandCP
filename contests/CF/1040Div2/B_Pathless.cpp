#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll sum; cin >> sum;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    ll cnt_0 = count(vec.begin(), vec.end(), 0);
    ll cnt_1 = count(vec.begin(), vec.end(), 1);
    ll cnt_2 = count(vec.begin(), vec.end(), 2);

    ll sm = accumulate(vec.begin(), vec.end(), 0LL);

    if (sm > sum) {
        for (auto &ele : vec) cout << ele << " ";
        cout << "\n";
        return;
    }

    sum -= sm;

    if (sum&1) sum -= 3;

    if (sum < 0) {
        for (int i=0; i<cnt_0; i++) {
            cout << "0 ";
        }
        for (int i=0; i<cnt_2; i++) {
            cout << "2 ";
        }
        for (int i=0; i<cnt_1; i++) {
            cout << "1 ";
        }
    } else {
        cout << "-1\n"; return;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
