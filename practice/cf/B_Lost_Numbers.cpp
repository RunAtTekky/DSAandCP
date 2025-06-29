#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> choice = {4, 8, 15, 16, 23, 42};


void ask(int x, int y) {
    cout << "? " << x << " " << y << "\n";
}

void solve() {
    ask(1,2);
    int product_12; cin >> product_12;
    if (product_12 == 0) return;

    ask(1,3);
    int product_13; cin >> product_13;
    if (product_13 == 0) return;

    int a,b,c,d;

    for (auto &ele : choice) {
        if (product_12 % ele != 0) continue;
        if (find(choice.begin(), choice.end(), product_12 / ele) != choice.end()) {
            a = ele;
            b = product_12 / ele;
            break;
        }
    }


    for (auto &ele : choice) {
        if (product_13 % ele != 0) continue;
        if (find(choice.begin(), choice.end(), product_13 / ele) != choice.end()) {
            c = ele;
            d = product_13 / ele;
            break;
        }
    }

    vector<int> ans(6);

    // a is common
    if (a == c || a == d) {
        // if a and c are same
        if (a == c) {
            ans[0] = a;
            ans[1] = b;
            ans[2] = d;
        } else {
            ans[0] = a;
            ans[1] = b;
            ans[2] = c;
        }
    } else {
        // if b and c are same
        if (b == c) {
            ans[0] = b;
            ans[1] = a;
            ans[2] = d;
        } else {
            ans[0] = b;
            ans[1] = a;
            ans[2] = c;
        }
    }

    ask(4,5);
    int product_45; cin >> product_45;
    if (product_45 == 0) return;

    ask(4,6);
    int product_46; cin >> product_46;
    if (product_46 == 0) return;

    a = 0, b = 0, c = 0, d = 0;

    for (auto &ele : choice) {
        if (product_45 % ele != 0) continue;
        if (ele == ans[0] || ele == ans[1] || ele == ans[2]) continue;
        if (find(choice.begin(), choice.end(), product_45 / ele) != choice.end()) {
            a = ele;
            b = product_45 / ele;
            break;
        }
    }


    for (auto &ele : choice) {
        if (product_46 % ele != 0) continue;
        if (ele == ans[0] || ele == ans[1] || ele == ans[2]) continue;
        if (find(choice.begin(), choice.end(), product_46 / ele) != choice.end()) {
            c = ele;
            d = product_46 / ele;
            break;
        }
    }

    // a is common
    if (a == c || a == d) {
        // if a and c are same
        if (a == c) {
            ans[3] = a;
            ans[4] = b;
            ans[5] = d;
        } else {
            ans[3] = a;
            ans[4] = b;
            ans[5] = c;
        }
    } else {
        // if b and c are same
        if (b == c) {
            ans[3] = b;
            ans[4] = a;
            ans[5] = d;
        } else {
            ans[3] = b;
            ans[4] = a;
            ans[5] = c;
        }
    }

    cout << "! ";
    for (auto &ele : ans) cout << ele << " ";
    cout << "\n";

}

int main() {
    solve();
}
