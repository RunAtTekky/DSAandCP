#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ' ' << x << '\n';

long long helper(bool first_turn, string curr, long long s_a, long long s_b, map<pair<string,pair<long long,long long>>, long long>& dp) {
    if (curr.size() == 1) {
        if (first_turn) {
            return max(s_a + curr[0] - '0', s_b);
        }
        else {
            return max(s_a, s_b + curr[0] - '0');
        }
    }

    // debug(curr);
    // debug(first_turn);
    // debug(s_a);
    // debug(s_b);

    if (dp.find({curr, {s_a, s_b}}) != dp.end()) return dp[{curr, {s_a,s_b}}];

    int sz = curr.size();

    // Take first
    int take_first;
    if (first_turn) {
        take_first = helper(!first_turn, curr.substr(1), s_a + (curr[0] - '0'), s_b, dp);   
    }
    else {
        take_first = helper(!first_turn, curr.substr(1), s_a, s_b + (curr[sz-1] - '0'), dp);   
    }

    // Take last
    int take_last;
    if (first_turn) {
        take_last = helper(!first_turn, curr.substr(0,curr.size()-1), s_a + (curr[0] - '0'), s_b, dp);   
    }
    else {
        take_last = helper(!first_turn, curr.substr(0,curr.size()-1), s_a, s_b + (curr[sz-1] - '0'), dp);   
    }

    if (first_turn) {
        return dp[{curr, {s_a, s_b}}] = max(take_first, take_last);
    }

    return dp[{curr, {s_a, s_b}}] = min(take_first, take_last);

}

void solve() {
    int n; cin >> n;

    vector<int> numbers(n);
    for (auto &number : numbers) cin >> number;

    // for (auto &ele : numbers) cout << ele << " ";
    // cout << "\n";
    
    

    // dp[string][score_a][score_b] => max^m possible score player A can get
    // when we have string and the score is score_a and score_b

    map<pair<string,pair<long long,long long>>, long long> dp;

    // dp[{"51", {3,4}}] = 8

    string s = "";
    for (auto number : numbers) {
        int num = number + '0';
        s.push_back(num);
    }

    long long ans = helper(true, s, 0, 0, dp);

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
