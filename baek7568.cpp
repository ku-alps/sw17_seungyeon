//����7568 ��ġ
#include <iostream>
#include <string.h>
using namespace std;

struct body {
	int x;
	int y;
	int rank = 1;
};
int main() {
	int n;
	body b[50];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i].x >> b[i].y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if ((b[i].x < b[j].x) && (b[i].y < b[j].y)) //�̹� ���ߴ��� ó���ؾ���
				b[i].rank++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << b[i].rank << " ";
	return 0;
}