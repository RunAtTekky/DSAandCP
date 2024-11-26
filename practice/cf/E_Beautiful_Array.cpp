#include <bits/stdc++.h>
using namespace std;

const int BIG = 1e5;

void solve() {
    int a,b; cin >> a >> b;
    // a => mean, b => median

    int to_insert = 5*a - b;

    vector<int> gift(5);

    gift[2] = b;

    if (to_insert >= b) {
        gift[3] = to_insert;

        gift[4] = BIG;
        gift[1] = gift[0] = -1 * (BIG/2);
    }
    
    else {
        gift[1] = to_insert;

        gift[0] = -1*BIG;
        gift[3] = gift[4] = BIG/2;
    }

    cout << "5\n";
    for (auto &ele : gift) cout << ele << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}
