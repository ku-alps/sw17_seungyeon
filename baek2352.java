package algorithmStudy;

import java.io.*;
import java.util.*;

/*
 * 백준 2352
 * 반도체 설계
 * 2019.11.02
 * */
public class baek2352 {
	static final int MAX = 40000;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int[] p = new int[MAX];
		Vector<Integer> c = new Vector<Integer>();
		// input 입력
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			p[i] = Integer.parseInt(st.nextToken());
		}
		c.add(p[0]);
		//lis 구하기
		for (int i = 1; i < N; i++) { // i번째 port는 무조건 연결된다고 가정하고 최대로 연결 가능한 포트 갯수
			if (p[i] > c.lastElement()) {
				c.add(p[i]);
			} else {
				int j = 0;
				for (j = 0; j < c.size(); j++) { // p[i]보다 처음으로 같거나 큰 수 찾기
					if (p[i] > c.get(j))
						continue;
					else
						break;
				}
				c.remove(j);
				c.add(j, p[i]);
			}
		}
		bw.write(Integer.toString(c.size()));
		bw.flush();
		br.close();
		bw.close();
	}

}
