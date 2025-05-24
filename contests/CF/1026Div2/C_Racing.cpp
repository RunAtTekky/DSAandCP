#include <bits/stdc++.h>
using namespace std;

vector<long long> vec;
vector<pair<int,int>> obstacles;

map<pair<int,vector<long long>>, vector<long long>> dp;
// We give {x_position, lower, upper} -> PATH

vector<long long> get_path(int x, int lower, int upper, vector<long long> path) {
    if (x >= vec.size()) return path;

    if (dp[{x,path}].size() != 0) return dp[{x,path}];

    vector<long long> up = {};
    vector<long long> stay = {};

    int l = obstacles[x].first;
    int r = obstacles[x].second;

    if (vec[x] == 1) {
        if ( (lower + 1 >= l) && (upper + 1 <= r) ) {
            path.push_back(1);
            up = get_path(x+1, lower+1, upper+1, path);
            path.pop_back();

            return dp[{x,path}] = up;
        }
    }

    // Stay
    if (vec[x] == 0) {

        if ( (lower >= l) && (upper <= r) ) {
            path.push_back(0);
            stay = get_path(x+1, lower, upper, path);
            path.pop_back();

            return dp[{x,path}] = stay;
        }
    }

    if (vec[x] == -1) {
        if ( (lower + 1 >= l) && (upper + 1 <= r) ) {
            path.push_back(1);
            up = get_path(x+1, lower+1, upper+1, path);
            path.pop_back();

            if (up.size() != 0) return dp[{x,path}] = up;
        }

        if ( (lower >= l) && (upper <= r) ) {
            path.push_back(0);
            stay = get_path(x+1, lower, upper, path);
            path.pop_back();

            return dp[{x,path}] = stay;
        }
    }

    return dp[{x,path}] = {};

}

void solve() {
    dp.clear();
    long long n; cin >> n;

    vec = vector<long long>(n);
    for (auto &ele : vec) cin >> ele;
    
    obstacles = vector<pair<int,int>>(n);
    for (auto &[l,r]: obstacles) cin >> l >> r;

    auto final_path = get_path(0, 0, 0, {});

    if (final_path.size() == 0) {cout << "-1\n";}
    else {
        for (auto &ele : final_path) cout << ele << " ";
        cout << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
