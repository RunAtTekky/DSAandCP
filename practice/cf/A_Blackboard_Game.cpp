#include <bits/stdc++.h>
using namespace std;

#define ALICE cout << "Alice\n"
#define BOB cout << "Bob\n"  

typedef long long ll;

void solve() {
    ll n; cin >> n;

    if (n%4 == 0) {
        BOB;
    }
    else {
        ALICE;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
