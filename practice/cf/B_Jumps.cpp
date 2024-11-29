#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x; cin >> x;

    int current_position = 0;

    int jumps=0;

    while (current_position < x) {
        current_position += ++jumps;
    }

    if (x+1 == current_position) jumps++;

    cout << jumps << "\n";


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
