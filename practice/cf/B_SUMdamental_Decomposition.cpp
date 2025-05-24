#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,k; cin >> n >> k;

    int bits = __builtin_popcountll(k);

    // If number of bits in k are less than elements we want to use
    // We will just put the power of twos in those places and we will
    // Use exactly sum k
    if (n <= bits) {
        cout << k << "\n"; return;
    } 

    // (n-bits) % 2 signifies number of bits to be added, if it is even it cancels out
    // Thus we will have k which signifies the number and (n-bits) which cancel each other 
    if ((n-bits) % 2 == 0) {
        cout << n-bits + k << "\n";
    } else {
        if (k > 1) {
            cout << n-bits + k + 1 << "\n"; return;
        }
        if (k == 1) cout << n+3 << "\n";
        else {
            if (n == 1) {cout << "-1\n";}
            else cout << n + 3 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
