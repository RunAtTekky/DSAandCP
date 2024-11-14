#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, c, d, p, q, y;
    cin >> n >> a >> b >> c >> d >> p >> q >> y;

    vector<int> cities(n);
    for (auto &city : cities) cin >> city;

    int distancFromAtoB = abs(cities[a-1] - cities[b-1]);

    int onlyWalking = distancFromAtoB * p;

    // If train is slower or equal to walking
    if (p <= q) {
        cout << onlyWalking << "\n";
        return;
    }

    // Go to City C and board the train to City D
    int dist_AC = abs(cities[c-1] - cities[a-1]);
    int dist_CD = abs(cities[c-1] - cities[d-1]);
    int dist_BD = abs(cities[b-1] - cities[d-1]);

    int withTrain = dist_AC*p + dist_CD*q + dist_BD*p;


    // If train has already left before reaching city C
    if (dist_AC*p > y) {
        cout << onlyWalking << "\n";
        return;
    }

    // Waiting for the train
    withTrain += y - (dist_AC*p);

    cout << min(withTrain, onlyWalking) << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
