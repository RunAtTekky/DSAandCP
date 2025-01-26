#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ' ' << x << '\n';

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

bool fine(string s) {
    for (int i=0, j=s.size(); i<j; i++,j--) {
        if (s[i] != s[j]) return false;
    }

    return true;
}

int helper(string prev, int idx, string& s, vector<map<string,int>>& dp) {
    if (idx == s.size()) return 1;

    debug(prev);

    if (dp[idx].find(prev) != dp[idx].end()) return dp[idx][prev];

    string current_string_0 = prev.substr(1,4);
    string current_string_1 = prev.substr(1,4);

    current_string_0 += '0';
    current_string_1 += '1';

    int ans = 0;
    if (s[idx] == '?') {
        if (fine(current_string_0) && fine(prev + "0")) {
            ans += helper(current_string_0, idx+1, s, dp);
        }
        if (fine(current_string_1) && fine(prev + "1")) {
            ans += helper(current_string_1, idx+1, s, dp);
        }
    } else if (s[idx] == '1') {
        if (fine(current_string_1) && fine(prev + "1")) {
            ans += helper(current_string_1, idx+1, s, dp);
        }
    } else {
        if (fine(current_string_0) && fine(prev + "0")) {
            ans += helper(current_string_0, idx+1, s, dp);
        }
    }

    debug(ans);

    return dp[idx][prev] = ans;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<map<string,int>> dp(n+1);

    int ans = helper("?????", 0, s, dp);

    if (ans > 0) {YES;}
    else {NO;}

}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
