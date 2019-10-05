#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


/*
백준 11000 강의실 배정
시작시간이 가장 빠른 강의실부터 차례차례 배정
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


#define MAX 200000
struct Lec {
	int s; //시작시간
	int e; //끝나는 시간
	int t; //수업 소요시간
	bool operator <(Lec &lec) {
		return this->s < lec.s;
	}
};

priority_queue<int,vector<int>,greater<int>> q; //최소힙 -> 가장 작은 수가 pop됨
vector<Lec> l; //강의객체 배열

int main() {
	int n; //수업 갯수
	scanf("%d", &n);

	
	for (int i = 0; i < n; i++) {
		Lec temp;
		scanf("%d %d", &temp.s, &temp.e);
		temp.t = temp.e - temp.s;
		l.push_back(temp);
	}
	sort(l.begin(), l.end()); //강의 시작순서대로 정렬
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

//void way1() { //시간초과 나온 방법
//	int c[MAX] = { 0, };
//	c[0] = l[0].e;
//	int cnt = 1; //강의실 갯수
//	for (int i = 1; i < l.size(); i++) {
//		for (int j = 0; j < l.size(); j++) {
//			if (l[i].s >= c[j]) {
//				c[j] = l[i].e; //j번 강의실 끝나는 시간 갱신
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