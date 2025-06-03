#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int brace = 0;
    int last_pos = -1;

    vector<int> ans(n);

    int cnt_open = count(s.begin(), s.end(), '(');
    int cnt_close = count(s.begin(), s.end(), ')');

    if (cnt_open != cnt_close) {
        cout << "-1\n";
        return;
    }

    for (int i=0; i<n; i++) {
        if (s[i] == '(') {
            brace++;
        } else brace--;

        if (brace == 0) {
            for (int j=last_pos+1; j<=i && j<n; j++) {
                ans[j] = s[last_pos+1] == '(' ? 1 : 2;
            }
            last_pos = i;
        }
    }

    bool one = false, two = false;
    for (auto &ele : ans) {
        if (ele == 1) one = true;
        if (ele == 2) two = true;
    }

    cout << (one && two ? "2" : "1")  << "\n";

    if (!(one && two)) {
        for (auto &ele : ans) cout << "1 ";
        cout << "\n";
    } else {
        for (auto &ele : ans) cout << ele << " ";
        cout << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
