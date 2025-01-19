#include <bits/stdc++.h>
using namespace std;

string s,t; 
int n,m;

int dp[5000][5000];

int edit_distance(string& s, string& t, int i, int j) {

    // if f(s,t) = |a|, |b|=0
    // if f(s,t) = |b|, |a|=0
    int length_a = n - i;
    int length_b = m - j;

    if (i>=n) return length_b;
    if (j>=m) return length_a;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        return edit_distance(s,t,i+1,j+1);
    }

    dp[i][j] = 1 + min({
        edit_distance(s,t,i,j+1),
        edit_distance(s,t,i+1,j),
        edit_distance(s,t,i+1,j+1)
    });

    return dp[i][j];
}

void solve() {
    cin >> s >> t;

    n = s.size();
    m = t.size();

    cout << edit_distance(s, t, 0, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    solve();
}
