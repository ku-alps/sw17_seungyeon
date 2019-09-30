//백준7562 나이트의 이동
#include <iostream>
#include <queue>
using namespace std;

int visited[300][300];

struct point {
	int x, y; //[x][y]
};
struct chess {
	int size; //size* size 꼴
	point n; //현재 나이트 위치 
	point goal; //목표  나이트 위치
};

void findPath(queue<point> &q, chess c, point p) {
	point tmp;
	for (int j = -2; j <= 2; j++) {
		if (p.x + j == p.x || p.x + j < 0 ||c.size<=p.x+j)
			continue;
		for (int k = -2; k <= 2; k++) {
			if (p.y + k == p.y || p.y + k < 0||c.size<=p.y+k)
				continue;
			if (j % 2 == 0 && k % 2 != 0) {	
				tmp.x = p.x + j;
				tmp.y = p.y + k;
				if (visited[tmp.x][tmp.y] == 0) {
					visited[tmp.x][tmp.y] = 1;
					q.push(tmp);
				}
			}
			else if (j % 2 != 0 && k % 2 == 0) {
				tmp.x = p.x + j;
				tmp.y = p.y + k;
				if (visited[tmp.x][tmp.y] == 0) {
					visited[tmp.x][tmp.y] = 1;
					q.push(tmp);
				}
			}
		}
	}
}
int bfs(chess c) {
	queue<point> q;
	q.push(c.n);
	visited[c.n.x][c.n.y] = 1;
	int order = 0; //몇번째 라운드로 찾게된 길인가
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			findPath(q, c, q.front()); //-1 : 찾음 , 기타 : 반환값만큼 갈 수 있는 길이 있음
			if (q.front().x==c.goal.x && q.front().y==c.goal.y)
				return order;
			q.pop();
		}
		order++;
	}

}
int main() {
	int l; //testcase 갯수
	cin >> l;
	chess c;
	for (int i = 0; i < l; i++){
		cin >> c.size;
		cin >> c.n.x >> c.n.y;
		cin >> c.goal.x >> c.goal.y;
		for (int j = 0; j < c.size; j++)
			for (int k = 0; k < c.size; k++)
				visited[j][k] = 0;
		cout << bfs(c) << endl;
	}
	return 0;
}

//#include <iostream>
//#include <string.h>
//using namespace std;
//
//#define NUM 500
//
//int main() {	
//	int a[NUM][NUM];
//	
//	int n;
//	cin >> n;
//	/*for (int i = 0; i < NUM; i++)
//		memset(a[i], -1, sizeof(int) * NUM);*/
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i + 1; j++) {
//			cin >> a[i][j];
//		}
//	}
//	int sum = a[0][0];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j< i + 1; j++) {
//		}
//	}
//
//	return 0;
//}


////백준7568 덩치
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//struct body {
//	int x;
//	int y;
//	int rank = 1;
//};
//int main() {
//	int n;
//	body b[50];
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> b[i].x >> b[i].y;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i == j)
//				continue;
//			if ((b[i].x < b[j].x) && (b[i].y < b[j].y)) //이미 비교했던거 처리해야함
//				b[i].rank++;
//		}
//	}
//	for (int i = 0; i < n; i++)
//		cout << b[i].rank << " ";
//	return 0;
//}