#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

map<string, vector<string>> adj;
vector<vector<string>> cowFactions;
map<string, bool> visited;

void dfs(string cow, vector<string>& connectedCows) {
    if (visited[cow]) return;

    visited[cow] = true;
    connectedCows.push_back(cow);
    for (auto nxt : adj[cow]) {
        dfs(nxt, connectedCows);
    }
}

vector<string> getInput() {
    string line;
    getline(cin, line);

    int n = line.size();
    //
    // cout << "Line -> " << " " << line << "\n";

    vector<string> ans(2);
    int firstSpace = 0;
    while (firstSpace < n && line[firstSpace] != ' ') firstSpace++;
    ans[0] = line.substr(0, firstSpace);

    int lastSpace = n - 1;
    while (lastSpace >= 0 && line[lastSpace] != ' ') lastSpace--;
    ans[1] = line.substr(lastSpace+1);

    return ans;
}

void solve() {
    ll n; cin >> n;

    string dummy;
    getline(cin, dummy);

    adj["Beatrice"] = {};
    adj["Sue"] = {};
    adj["Belinda"] = {};
    adj["Bessie"] = {};
    adj["Betsy"] = {};
    adj["Blue"] = {};
    adj["Bella"] = {};
    adj["Buttercup"] = {};

    for (int i=0; i<n; i++) {
        auto connected = getInput();
        string u = connected[0], v = connected[1];
        //
        // cout << u << " " << v << "\n";

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (auto &[cow, cows] : adj) {
        if (visited[cow]) continue;
        if (cows.size() == 2) continue;

        vector<string> connectedCows;
        dfs(cow, connectedCows);

        if (connectedCows.back() < connectedCows.front()) {
            reverse(connectedCows.begin(), connectedCows.end());
        }
        cowFactions.push_back(connectedCows);
    }

    sort(cowFactions.begin(), cowFactions.end());
    for (auto &faction : cowFactions) {
        for (auto &cow : faction) {
            cout << cow << "\n";
        }
        // cout << "\n";
    }
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

