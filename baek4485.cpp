#include <iostream>
#include <vector>
#include<queue>

using namespace std;

int map[125][125]; //자동으로 0으로 초기화
int dist[125][125];
int dC[4] = { 0,1,0,-1 }; //상,우,하,좌
int dR[4] = { 1,0,-1,0 };
int n;




class vertex {
public:
	int row, col, result;
	vertex(int row, int col, int result) :row(row), col(col), result(result) {};
	bool operator<(vertex&v) {
		return result < v.result;
	}
};

int Dik()
{
	priority_queue<vertex> pq;
	dist[0][0] = map[0][0];
	
	pq.push(vertex(0,0,map[0][0]));
	while (!pq.empty()) {
		int curR = pq.top().row;
		int curC = pq.top().col;
		int curRe = pq.top().result;
		pq.pop();
		if (curR == n - 1 && curC == n - 1)
			return curRe;
		else {
			for (int i = 0; i < 4; i++) {
				int nextR = curR + dR[i];
				int nextC = curC + dC[i];
				if (nextR >= 0 && nextC >= 0 && nextR <= n - 1 && nextC <= n - 1) {
					if (dist[nextR][nextC] > dist[curR][curC] + map[nextR][nextC]) {
						dist[nextR][nextC] = dist[curR][curC] + map[nextR][nextC];
	
						pq.push(vertex(nextR,nextC,dist[nextR][nextC]));
					}

				}
			}
		}

	}
	return -1;
}
int main() {

	while (true) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				dist[i][j] = INT_MAX;
			}
		}
		cout << Dik();

	}
	return 0;
	
}