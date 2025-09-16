#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
map<char,ll> freq;
vector<string> res;

void search(string curr) {
    if (curr.size() == s.size()) {
        res.push_back(curr);
        return;
    }

    for (int i=0; i<26; i++) {
        char ch = 'a' + i;
        if (freq[ch] > 0) {
            freq[ch]--;
            search(curr + ch);
            freq[ch]++;
        }
    }
}

void solve() {
    cin >> s;
    for (auto &ch : s) freq[ch]++;

    search("");

    cout << res.size() << "\n";
    for (auto &ele : res) cout << ele << "\n";
    cout << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

