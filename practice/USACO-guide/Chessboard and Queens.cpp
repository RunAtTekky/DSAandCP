#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> chessboard;
map<ll,bool> sum_have;
map<ll,bool> diff_have;
map<ll,bool> col_have;

ll ways = 0;
ll rec(int row) {
    if (row == 8) return 1;

    ll ans = 0;
    for (int col=0; col<8; col++) {
        if (
            chessboard[row][col] == '*' || 
            sum_have[row+col] || diff_have[row-col] || col_have[col]
        ) continue;

        sum_have[row+col] = true; diff_have[row-col] = true; col_have[col] = true;
        ans += rec(row+1);
        sum_have[row+col] = false; diff_have[row-col] = false; col_have[col] = false;
    }

    return ans;
}

void solve() {
    chessboard.resize(8);
    for (int i=0; i<8; i++) cin >> chessboard[i];

    cout << rec(0) << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

