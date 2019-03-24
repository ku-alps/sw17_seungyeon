//����7562 ����Ʈ�� �̵�
#include <iostream>
#include <queue>
using namespace std;

int visited[300][300];

struct point {
	int x, y; //[x][y]
};
struct chess {
	int size; //size* size ��
	point n; //���� ����Ʈ ��ġ 
	point goal; //��ǥ  ����Ʈ ��ġ
};

void findPath(queue<point> &q, chess c, point p) {
	point tmp;
	for (int j = -2; j <= 2; j++) {
		if (p.x + j == p.x || p.x + j < 0 || c.size <= p.x + j)
			continue;
		for (int k = -2; k <= 2; k++) {
			if (p.y + k == p.y || p.y + k < 0 || c.size <= p.y + k)
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
	int order = 0; //���° ����� ã�Ե� ���ΰ�
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			findPath(q, c, q.front()); //-1 : ã�� , ��Ÿ : ��ȯ����ŭ �� �� �ִ� ���� ����
			if (q.front().x == c.goal.x && q.front().y == c.goal.y)
				return order;
			q.pop();
		}
		order++;
	}

}
int main() {
	int l; //testcase ����
	cin >> l;
	chess c;
	for (int i = 0; i < l; i++) {
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
