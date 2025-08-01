#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU {
private:
    vector<int> parent;
    vector<int> size;
    int count = 0;

public:
    DSU(int n) : parent(n), size(n,1) {
        iota(parent.begin(), parent.end(), 0);
        count = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void connect(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            count--;
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    int components() {
        return count;
    }

    int componentSize(int x) {
        return size[find(x)];
    }
};

void solve() {
    ll n; cin >> n;

    DSU dsu(n);

    dsu.connect(7,10);

    cout << dsu.connected(1, 10) << " 1 - 10\n";
    cout << dsu.connected(7, 10) << " 7 - 10\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

