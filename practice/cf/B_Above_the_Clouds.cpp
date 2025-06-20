#include <bits/stdc++.h>
using namespace std;

#define YES cout << "Yes\n"
#define NO cout << "No\n"  

void solve() {
    int n; cin >> n;

    string s; cin >> s;

    map<char,int> freq;

    for (int i=0; i+1<n; i++) {
        freq[s[i]]++;
        if (freq[s[i]] >= 2) {
            YES; return;
        }
    }

    map<char,int> freq2;

    for (int i=1; i<n; i++) {
        freq2[s[i]]++;
        if (freq2[s[i]] >= 2) {
            YES; return;
        }
    }

    NO;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
