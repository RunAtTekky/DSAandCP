#include <bits/stdc++.h>
using namespace std;

vector<bool> prime;

void SieveOfEratosthenes(int n) {
    prime = vector<bool>(n+1, true);

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void solve() {
    int n; cin >> n;

    vector<int> perm(n+1);

    long long last_even = (n/2) * 2;

    for (int i=1; i<=n; i+=2) {
        if (!prime[last_even + i]) {
            int next_to_last_even = i;

            for (int i=2; i<=n; i+=2) cout << i << " ";
            cout << next_to_last_even << " ";

            for (int i=1; i<=n; i+=2) {
                if (i != next_to_last_even) cout << i << " ";
            }
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    SieveOfEratosthenes(2e5+5);
    int t=1; cin >> t;
    while (t--) solve();
}
