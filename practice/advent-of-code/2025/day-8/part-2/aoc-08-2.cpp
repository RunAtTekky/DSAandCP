#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll CONNECTIONS = 1000;

class DSU {
private:
    vector<ll> parent;
    vector<ll> size;
    int count = 0;

public:
    DSU(int n) : parent(n), size(n,1) {
        iota(parent.begin(), parent.end(), 0);
        count = n;
    }

    vector<ll> get_sizes() {
        return size;
    }

    ll find(ll x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void connect(ll a, ll b) {
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

    bool connected(ll a, ll b) {
        return find(a) == find(b);
    }

    ll components() {
        return count;
    }

    ll componentSize(ll x) {
        return size[find(x)];
    }
};

vector<ll> get_coord(string line) {
    vector<ll> coordinates;
    ll first_comma_idx = find(line.begin(), line.end(), ',') - line.begin();
    ll second_comma_idx = find(line.begin() + first_comma_idx + 1, line.end(), ',') - line.begin();

    ll x = stoll(line.substr(0, first_comma_idx));
    ll y = stoll(line.substr(first_comma_idx+1, second_comma_idx - first_comma_idx - 1));
    ll z = stoll(line.substr(second_comma_idx + 1));

    return coordinates = {x,y,z};
}

void take_input(vector<vector<ll>>& coord) {
    // TODO: Take Input
    string line;
    while (cin >> line) {
        vector<ll> juction_coord = get_coord(line);
        coord.push_back(juction_coord);
    }
}

void print_coord(vector<vector<ll>>& coord) {
    for (auto &line : coord) {
        for (auto &ele : line) cout << ele << " ";
        cout << "\n";
    }
    cout << "\n";
    
}

vector<vector<ll>> get_junction_distances(vector<vector<ll>>& coord) {
    vector<vector<ll>> junction_distances;
    ll n = coord.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll x1 = coord[i][0], y1 = coord[i][1], z1 = coord[i][2];
            ll x2 = coord[j][0], y2 = coord[j][1], z2 = coord[j][2];
            ll distance = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) + (z1-z2) * (z1-z2);

            junction_distances.push_back({distance, i, j});
        }
    }
    return junction_distances;
}

void print_ith_coord(ll i, vector<vector<ll>>& coord) {
    cout << coord[i][0] << " " << coord[i][1] << " " << coord[i][2] << "\n";
}

vector<ll> create_DSU(vector<vector<ll>>& junction_distances, vector<vector<ll>>& coord) {
    ll n = coord.size();
    DSU dsu(n+1);

    for (int i=0; i<junction_distances.size(); i++) {
        ll distance = junction_distances[i][0], first = junction_distances[i][1], second = junction_distances[i][2];
        dsu.connect(first, second);
        if (dsu.componentSize(first) == n) {
            return {first,second};
        }
    }
    return {-1,-1};
}

ll find_ans(vector<vector<ll>>& junction_distances, vector<vector<ll>>& coord) {
    // TODO: Get answer
    auto components = create_DSU(junction_distances, coord);

    ll x1 = coord[components[0]][0];
    ll x2 = coord[components[1]][0];

    return x1 * x2;
}

void solve() {
    vector<vector<ll>> coord;
    take_input(coord);
    // print_coord(coord);

    vector<vector<ll>> junction_distances = get_junction_distances(coord);
    sort(junction_distances.begin(), junction_distances.end());
    //
    // for (auto &ele : junction_distances) {
    //     cout << "dist:" << " " << ele[0] << "\n";
    //     print_ith_coord(ele[1], coord);
    //     print_ith_coord(ele[2], coord);
    // }
    // cout << "\n";
    //
    ll ans = find_ans(junction_distances, coord);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}


