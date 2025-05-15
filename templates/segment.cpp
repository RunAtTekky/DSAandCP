#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> segment(4e5);
vector<int> og_vec;

void build_segment_tree(int index, int low, int high) {
    if (low == high) {
        segment[index] = og_vec[low];
        return;
    }

    int mid = (low + high) / 2;

    build_segment_tree(2*index + 1, low, mid);
    build_segment_tree(2*index + 2, mid+1, high);

    segment[index] = max(segment[2*index+1], segment[2*index+2]);
}

int query_segment_tree(int index, int low, int high, int l, int r) {

    // Completely has it -> return the value at that index
    if (l <= low && high <= r) return segment[index];

    // Doesn't have it -> return worst value
    if (l > high || r < low) return INT_MIN;

    int mid = (low + high) / 2;

    // Overlapping -> go both side
    int lft = query_segment_tree(2*index+1, low, mid, l, r);
    int rgt = query_segment_tree(2*index+2, mid+1, high, l, r);

    return max(lft, rgt);
}

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    og_vec = vec;

    build_segment_tree(0, 0, n-1);

    int l = 3, r = 8;
    cout << query_segment_tree(0, 0, n-1, l, r) << "\n";

}

int main() {
    int t; cin >> t;

    while(t--) solve();
}
