#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    int max_width=0, max_height=0;
    int width, height;

    for (int i=0; i<n; i++) {
        cin >> width >> height;

        max_width = max(max_width, width);
        max_height = max(max_height, height);
    }

    cout << 2*(max_width + max_height) << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
