#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


/*
���� 11000 ���ǽ� ����
���۽ð��� ���� ���� ���ǽǺ��� �������� ����
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


#define MAX 200000
struct Lec {
	int s; //���۽ð�
	int e; //������ �ð�
	int t; //���� �ҿ�ð�
	bool operator <(Lec &lec) {
		return this->s < lec.s;
	}
};

priority_queue<int,vector<int>,greater<int>> q; //�ּ��� -> ���� ���� ���� pop��
vector<Lec> l; //���ǰ�ü �迭

int main() {
	int n; //���� ����
	scanf("%d", &n);

	
	for (int i = 0; i < n; i++) {
		Lec temp;
		scanf("%d %d", &temp.s, &temp.e);
		temp.t = temp.e - temp.s;
		l.push_back(temp);
	}
	sort(l.begin(), l.end()); //���� ���ۼ������ ����
	q.push(l[0].e);
	for (int i = 1; i < n; i++) {
		if (l[i].s >= q.top()) {
			q.pop();
		}
		q.push(l[i].e);
	}
	printf("%d", q.size());
	return 0;
}

//void way1() { //�ð��ʰ� ���� ���
//	int c[MAX] = { 0, };
//	c[0] = l[0].e;
//	int cnt = 1; //���ǽ� ����
//	for (int i = 1; i < l.size(); i++) {
//		for (int j = 0; j < l.size(); j++) {
//			if (l[i].s >= c[j]) {
//				c[j] = l[i].e; //j�� ���ǽ� ������ �ð� ����
//				break;
//			}
//			if (j == cnt - 1) {
//				c[cnt++] = l[i].e;
//				break;
//			}
//		}
//	}
//	printf("%d", cnt);
//}