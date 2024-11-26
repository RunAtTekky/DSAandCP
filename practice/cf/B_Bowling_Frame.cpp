#include <bits/stdc++.h>
using namespace std;

void solve() {
    int white_pins, black_pins;
    cin >> white_pins >> black_pins;

    long long start=1, end=max(white_pins,black_pins);

    while (start <= end) {
        long long side = (start + end) >> 1;

        long long pins_required = side * (side+1) / 2;

        if (pins_required > white_pins + black_pins) end = side-1;
        else start = side+1;
    }

    cout << end << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
