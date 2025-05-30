#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n,k; cin >> n >> k;

    string s; cin >> s;

    int cnt_zero = count(s.begin(), s.end(), '0');
    int cnt_one = count(s.begin(), s.end(), '1');

    int mini = min(cnt_zero, cnt_one);

    int dis = n/2 - k;

    if (mini < dis) {
        NO; return;
    }

    if ((cnt_zero - dis) & 1) {NO; return;}
    if ((cnt_one - dis) & 1) {NO; return;}

    int sum = (cnt_zero + cnt_one) - 2 * dis;

    if (sum / 2 == k) {YES;}
    else {NO;}

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
