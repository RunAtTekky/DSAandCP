#include <bits/stdc++.h>
using namespace std;

int getLength(long long num) {
    int length = 0;
    while (num > 0) {
        length++;
        num = num >> 1;
    }
    return length;
}

// #define debug(x) cerr << #x << ' ' << x << '\n';

void solve() {
    long long x,m; cin >> x >> m;

    long long answer = 0;

    int length_of_x = getLength(x);

    long long highest = (1 << length_of_x) - 1;

    // debug(highest);

    highest = min(highest, m);

    for (long long y=1; y<=highest; y++) {
        if (x==y) continue;
        long long xor_xy = x^y;
        if (xor_xy == 0) continue;
        if ( (x % xor_xy == 0) || (y % xor_xy == 0) ) {
            answer++;
            // debug(xor_xy);
        }
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
