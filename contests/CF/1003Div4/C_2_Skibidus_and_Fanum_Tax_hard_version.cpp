#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

#define debug(x) cerr << #x << ' ' << x << '\n';

void solve() {
    long long n,m; cin >> n >> m;

    vector<long long> a(n);
    for (auto &ele : a) cin >> ele;
    
    vector<long long> b(m);
    for (auto &ele : b) cin >> ele;
    
    sort(b.begin(), b.end());

    long long prev = INT_MIN;

    for (long long i=0; i<n; i++) {

        long long required_above = a[i] + prev;

        long long idx = lower_bound(b.begin(), b.end(), required_above) - b.begin();

        // debug(i);
        // debug(idx);

        if ( (idx == m) && (prev > a[i]) ) {NO; return;}

        if (idx < m) {
            long long after_operation = b[idx] - a[i];
            if ( (after_operation >= prev) && (after_operation <= a[i]) ) a[i] = after_operation;

            if (prev > a[i] && after_operation >= prev) a[i] = after_operation;
        }

        if (prev > a[i]) {NO; return;}

        prev = a[i];

    }

    YES;
    // bool srtd = is_sorted(a.begin(), a.end());

    // if (srtd) {YES;}
    // else {NO;}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t=1; cin >> t;
    while (t--) solve();
}
