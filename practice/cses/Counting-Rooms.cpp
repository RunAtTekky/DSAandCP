#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> pl;

ll n,m;
vector<vector<char>> grid;
ll rooms;
vector<pl> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(ll row, ll col) {
	if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '#') return;

	grid[row][col] = '#';

	for (auto &[x,y] : directions) {
		ll new_row = row + x;
		ll new_col = col + y;

		dfs(new_row, new_col);
	}

}

void solve() {
	cin >> n >> m;
	grid = vector<vector<char>>(n, vector<char>(m));
	rooms = 0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] == '.') {
				dfs(i, j);
				rooms++;
			}
		}
	}

	cout << rooms << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}

