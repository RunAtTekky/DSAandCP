#include <bits/stdc++.h>
using namespace std;

int get_square_root(int num) {
    int start = 0, end = num;

    while (start <= end) {
        int mid = (start + end) / 2;

        int sq = mid*mid;
        if (sq == num) {
            return mid;
        }

        if (sq > num) {
            end = mid - 1;
        }
        
        else start = mid + 1;
    }

    return -1;

}

void solve() {
    int year; cin >> year;

    if (year == 0) {
        cout << "0 0\n"; return;
    }

    int sqrt_year = get_square_root(year);

    if (sqrt_year == -1) {
        cout << "-1\n"; return;
    }

    cout << sqrt_year - 1 << " " << 1 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
