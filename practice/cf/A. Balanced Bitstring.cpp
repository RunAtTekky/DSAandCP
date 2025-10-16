#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;
    string s; cin >> s;

    ll minTravel = min(k, n-k);

    for (int i=0; i<minTravel; i++) {
        char curr = '?';
        for (int j=i; j<n; j+=k) {
            if (s[j] == '1') {
                if (curr == '0') {NO; return;}
                curr = '1';
            }
            if (s[j] == '0') {
                if (curr == '1') {NO; return;}
                curr = '0';
            }
        }
        for (int j=i; j<n; j+=k) {
            s[j] = curr;
        }
    }

    // cout << s << "\n";
    //
    ll cnt_zero = 0, cnt_one = 0;
    for (int i=0; i<k; i++) {
        cnt_zero += (s[i] == '0');
        cnt_one += (s[i] == '1');
    }

    if (cnt_zero > k/2) NO;
    else if (cnt_one > k/2) NO;
    else YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

