#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    int count = 0;

public:
    DSU(int n) : parent(n), rank(n) {
        iota(parent.begin(), parent.end(), 0);
        count = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void connect(int a, int b) {
        int aroot = find(a);
        int broot = find(b);

        if (aroot == broot) return;

        if (rank[aroot] < rank[broot]) {
            swap(aroot, broot);
        }
        parent[broot] = aroot;
        count--;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    void reset(int x) {
        parent[x] = x;
    }
};

void solve() {
    ll n; cin >> n;

    vector<int> vec(n);

    DSU dsu(1e4);

    vector<int> ans;

    for (int i=0; i<n; i++) {
        int u,v; cin >> u >> v;

        if (!dsu.connected(u, v)) {
            ans.push_back(i+1);
            dsu.connect(u, v);
        }
    }

    cout << ans.size() << "\n";
    for (auto &ele : ans) cout << ele << " ";
    cout << "\n";
    
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
