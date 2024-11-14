#include <bits/stdc++.h>
using namespace std;

int a,b,x,y;

vector<pair<int,int>> ranges = { {-1, a}, {a, -1}, {-1, 0}, {0, -1} };

double getSlope(int ax, int ay, int cx, int cy) {
    double numerator = max(ax,cx) - min(ax,cx);
    double denominator = max(ay,cy) - min(ay,cy);

    return numerator / denominator;
}

double equation(double a, double b, double x, double y, double c) {
    return (a*x + b*y + c >= 0) ? 1 : -1;
}

bool checkInside(double slope, double ax, double ay, double bx, double by) {
    double c = slope * ax - ay;
    double res1 = equation(slope, -1, x, y, c);
    double res2 = equation(slope, -1, x+b, y, c);
    double res3 = equation(slope, -1, x, y+b, c);
    double res4 = equation(slope, -1, x+b, y+b, c);

    // If all are of same parity then true else false
    return ( (res1 * res2 * res3 * res4) > 0) ? true : false;

}

bool check(int ax, int ay, int bx, int by, int dir) {

    int thirdX = ranges[dir].first;
    int thirdY = ranges[dir].second;

    for (int i=0; i<a; i++) {
        if (ranges[dir].first == -1) {
            thirdX = i;
        }

        else {
            thirdY = i;
        }

        // Find slopes on both sides
        double slope = getSlope(ax, ay, thirdX, thirdY);
        double slope2 = getSlope(bx, by, thirdX, thirdY);

        bool isInside = checkInside(slope, ax, ay, thirdX, thirdY);
        bool isInside2 = checkInside(slope2, bx, by, thirdX, thirdY);

        if (isInside && isInside2) {
            cout << ax << " " << ay << " " << bx << " " << by << " " << thirdX << " " << thirdY << "\n";
            cout << "yes\n"; return true;
        }
    }

    return false;
}



void solve() {
    cin >> a >> b >> x >> y;

    // We have 4 cases with each side
    // (0,y) - (a,y)        - bottom
    // (0,y+b) - (a, y+b)   - top
    // (x,0) - (x,a)        - left
    // (x+b,0) - (x+b,a)    - right

    // For each side we try to find a point which will have all the points of square
    // inside the triangle

    bool isInside0 = check(0,y,a,y,0);
    if (isInside0) return;
    bool isInside1 = check(x,0,x,a,1);
    if (isInside1) return;
    bool isInside2 = check(0,y+b,a,y+b,2);
    if (isInside2) return;
    bool isInside3 = check(x+b,0,x+b,a,3);
    if (isInside3) return;

    cout << "no\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
