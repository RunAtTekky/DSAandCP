#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    long long n,m; cin >> n >> m;

    vector<long long> a(n);
    for (auto &ele : a) cin >> ele;
    
    vector<long long> b(m);
    for (auto &ele : b) cin >> ele;
    

    if (is_sorted(a.begin(), a.end())) {YES; return;}

    long long prev = LLONG_MIN;
    for (long long i=0; i<n; i++) {

        long long after_operation = b[0] - a[i];

        if ( (prev <= after_operation ) && (after_operation <= a[i]) ) a[i] = after_operation;

        if (prev > a[i] && after_operation >= prev) a[i] = after_operation;

        if (prev > a[i]) {NO; return;}

        prev = a[i];
    }

    bool srtd = is_sorted(a.begin(), a.end());

    if (srtd) {YES;}
    else {NO;}


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t=1; cin >> t;
    while (t--) solve();
}
