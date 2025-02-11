#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;

    int n = s.size();

    string last_two = s.substr(n-2, 2);
    string first_part = s.substr(0,n-2);

    if (last_two == "us") {

        cout << first_part + "i" << "\n";
    }
    else {
        cout << first_part + "us" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
