#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// void solve() {
//     // First billboard
//     ll x1, y1, x2, y2;
//     cin >> x1 >> y1 >> x2 >> y2;
//
//     // Second billboard
//     ll xx1, xy1, xx2, xy2;
//     cin >> xx1 >> xy1 >> xx2 >> xy2;
//
//     // Truck
//     ll tx1, ty1, tx2, ty2;
//     cin >> tx1 >> ty1 >> tx2 >> ty2;
//
//     const ll INCREMENT = 1000;
//
//     x1 += INCREMENT;
//     y1 += INCREMENT;
//     x2 += INCREMENT;
//     y2 += INCREMENT;
//
//     xx1 += INCREMENT;
//     xy1 += INCREMENT;
//     xx2 += INCREMENT;
//     xy2 += INCREMENT;
//
//     tx1 += INCREMENT;
//     ty1 += INCREMENT;
//     tx2 += INCREMENT;
//     ty2 += INCREMENT;
//
//     const ll SZ = 2001;
//     vector<vector<bool>> billboardVisible(SZ, vector<bool>(SZ));
//
//     for (int row=x1; row<x2; row++) {
//         for (int col=y1; col<y2; col++) {
//             billboardVisible[row][col] = true;
//         }
//     }
//
//     for (int row=xx1; row<xx2; row++) {
//         for (int col=xy1; col<xy2; col++) {
//             billboardVisible[row][col] = true;
//         }
//     }
//
//     for (int row=tx1; row<tx2; row++) {
//         for (int col=ty1; col<ty2; col++) {
//             billboardVisible[row][col] = false;
//         }
//     }
//
//     ll total = 0;
//     for (int i=0; i<SZ; i++) {
//         for (int j=0; j<SZ; j++) {
//             total += billboardVisible[i][j];
//         }
//     }
//
//     cout << total << "\n";
// }

class Rect {
public:
    ll x1, y1, x2, y2;

    void read() {
        cin >> x1 >> y1 >> x2 >> y2;
    }

    ll area() {
        return (x2-x1) * (y2-y1);
    }
};

ll intersection(Rect a, Rect b) {
    ll intersection_x = max(0LL, min(a.x2, b.x2) - max(a.x1, b.x1));
    ll intersection_y = max(0LL, min(a.y2, b.y2) - max(a.y1, b.y1));

    return intersection_x * intersection_y;
}

void solve2() {
    Rect billboard1, billboard2, truck;

    billboard1.read();
    billboard2.read();
    truck.read();

    ll bill1_and_truck = intersection(billboard1, truck);
    ll bill2_and_truck = intersection(billboard2, truck);

    ll visible = billboard1.area() + billboard2.area();
    visible -= bill1_and_truck + bill2_and_truck;

    cout << visible << "\n";
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // solve();
    solve2();
}

