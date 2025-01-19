#include <bits/stdc++.h>
using namespace std;

const int MAX_SUM_POSSIBLE = 1000 * 100;
 
// dp[sum][idx] => This sum and idx have been visited and their sums have been stored
bool dp[MAX_SUM_POSSIBLE][101];

// This is where I will store the sums
set<int> st;
 
void f(vector<int>& coins, int sum, int idx) {
 
    if (idx >= coins.size()) {
        if (sum != 0) st.insert(sum); 
        return;
    }
 
    if (dp[sum][idx] != 0) return;

    // This means we have visited this state once
    dp[sum][idx] = 1;
 
    // Take
    f(coins, sum + coins[idx], idx+1);
 
    // No take
    f(coins, sum, idx+1);
 
}
 
void solve() {
    int n; cin >> n;
 
    vector<int> coins(n);
    for (auto &coin : coins) cin >> coin;
 
    sort(coins.begin(), coins.end());
 
    f(coins, 0, 0);
 
    vector<int> sums(st.begin(), st.end());
 
    cout << sums.size() << "\n";
    for (auto &ele : sums) cout << ele << " ";
    cout << "\n";
 
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}