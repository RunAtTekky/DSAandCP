#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,x; cin >> n >> x;

    vector<long long> cars(n);
    for (auto &car : cars) cin >> car;

    long long minimum_customers = *max_element(cars.begin(), cars.end());

    long long sum_of_cars = accumulate(cars.begin(), cars.end(), 0LL);
    long long minimum_customers_distribute_cars = (sum_of_cars + x - 1)/x;

    cout << max(minimum_customers, minimum_customers_distribute_cars) << "\n";
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
