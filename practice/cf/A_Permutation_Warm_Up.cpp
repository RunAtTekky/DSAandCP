#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;

    bool odd = n&1;

    if (odd) {
        int even_count = (n-1) / 2;

        long long sum = even_count * (even_count+1) / 2;

        cout << 2*sum + 1 << "\n";
    } else {
        int odd_count = n/2;

        cout << odd_count*odd_count + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
