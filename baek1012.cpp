#include <iostream>
#include <stack>

/*
백준 1012 유기농 배추
*/
using namespace std;

int a[50][50]; //가로 세로 max가 50임
int m, n, k; //가로, 세로, 배추 갯수


bool check(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
void DFS() {
	stack<pair<int, int>> st; //dfs
	int worm = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				pair<int, int> pos;
				st.push(make_pair(i,j));
				a[i][j] = 0;
				while (!st.empty()) {
					int r = st.top().first; //행
					int c = st.top().second; //열
					
					if (check(r+1,c)&& a[r + 1][c] == 1) {
						st.push(make_pair(r+1, c));
						a[r + 1][c] = 0;
						continue;
					}
					else if (check(r, c + 1) && a[r][c + 1] == 1) {
						st.push(make_pair(r, c + 1));
						a[r ][c+1] = 0;
						continue;
					}
					else if (check(r - 1, c) && a[r - 1][c] == 1) {
						st.push(make_pair(r-1, c));
						a[r-1][c] = 0;
						continue;
					}
					else if (check(r , c-1) && a[r][c-1] == 1) {
						st.push(make_pair(r , c-1));
						a[r][c-1] = 0;
						continue;
					}
					st.pop();
				}
				worm++;
			}
		}
	}
	printf("%d", worm);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			int posX, posY;
			scanf("%d %d", &posX, &posY);
			a[posY][posX] = 1;

		}
		DFS(); 
		if (i == t - 2)
			printf("\n");
	}

	return 0;
}
