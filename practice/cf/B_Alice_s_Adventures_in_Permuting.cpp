#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,b,c; cin >> n >> b >> c;

    long long res;
    if (b==0) {
        if (c >= n) res = n;
        else if (c == n-1 || c == n-2) res = n-1;
        else res = -1;
    }

    else {
        if (c>=n) res = n;
        else {
            res = n - max(0LL, 1 + (n-1-c)/b);
        }
    }

    cout << res << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
