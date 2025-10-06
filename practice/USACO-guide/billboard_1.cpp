#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Rect {
public:
    ll bl_x, bl_y, tr_x, tr_y;

    void Read() {
        cin >> bl_x >> bl_y >> tr_x >> tr_y;
    }

    ll Area() {
        return (tr_x - bl_x) * (tr_y - bl_y);
    }
};

ll intersection(Rect p, Rect q) {
    ll x = max(0LL, min(p.tr_x, q.tr_x) - max(p.bl_x, q.bl_x));
    ll y = max(0LL, min(p.tr_y, q.tr_y) - max(p.bl_y, q.bl_y));

    return x * y;
}

ll checkCover(ll x, ll y, Rect q) {
    // If the point (x,y) lies inside the rectangle q
    if (x >= q.bl_x && x <= q.tr_x && y >= q.bl_y && y <= q.tr_y) return 1;
    return 0;
}

ll cornersCovered(Rect p, Rect q) {
    ll covered = 0;
    covered += checkCover(p.bl_x, p.bl_y, q);
    covered += checkCover(p.tr_x, p.tr_y, q);
    covered += checkCover(p.bl_x, p.tr_y, q);
    covered += checkCover(p.tr_x, p.bl_y, q);

    return covered;
}

void solve() {
    Rect lawnmower, cowfeed;
    lawnmower.Read();
    cowfeed.Read();

    ll corners = cornersCovered(lawnmower, cowfeed);

    ll ans = 0;
    if (corners == 4) {
        cout << 0 << "\n"; return;
    }

    if (corners < 2) {
        cout << lawnmower.Area() << "\n"; return;
    }

    // Now corners will cover 2 coz obv if it covers 3 then it covers 4
    cout << lawnmower.Area() - intersection(lawnmower, cowfeed) << "\n";
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

