#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    if (n == 1 || n==3) {cout << "-1\n"; return;}

    if (n%2 == 0) {
        while (n-2>0) {cout << "3"; n--;}
        cout << "66\n"; return;
    }

    while (n-4>0) {cout << "3"; n--;}
    cout << "6366\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
