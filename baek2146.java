package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class baek2146 {
	/*
	 * 백준 2146 다리만들기
	 */
	public static int map[][];
	public static int visit[][];
	public static int n;
	// map[dy][dx]
	public static int[] dx = { -1, 0, 1, 0 };
	public static int[] dy = { 0, 1, 0, -1 };

	public static class Pair {
		int x, y;

		Pair(int y, int x) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		visit = new int[n][n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				int val = Integer.parseInt(st.nextToken());
				if (val == 1)
					val = -1; // 대륙 구분할 때
				map[i][j] = val;
			}
		}

		// 대륙 구분하기 1 ~ n
		int conNum = 1; // 대륙 번호
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == -1 && visit[i][j] == 0) {
					classifyContinent(i, j, conNum);
					conNum++;
				}
			}
		}
	
		int min = n * n;
		for (int i = 1; i < conNum; i++) {
			min = Math.min(min, findPath(i));
			for(int j=0;j<n;j++)
				Arrays.fill(visit[j], 0); // visit 배열 0 으로 초기화
		}
		bw.write(Integer.toString(min));
		bw.flush();
		br.close();
		bw.close();
	}

	// 대륙마다 번호 붙이는 함수
	public static void classifyContinent(int y, int x, int conNum) {
		visit[y][x] = 1;
		map[y][x] = conNum;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[ny][nx] == -1 && visit[ny][nx] == 0)
					classifyContinent(ny, nx, conNum);
			}
		}
	}

	public static int findPath(int conNum) {
		int res = 0;
		Queue<Pair> q = new LinkedList<Pair>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == conNum)
					q.offer(new Pair(i, j));
			}
		}
		while (!q.isEmpty()) {
			int qSize=q.size();
			for (int j = 0; j < qSize; j++) {
				Pair pos = q.poll();
				for (int i = 0; i < 4; i++) {
					int nx = dx[i] + pos.x;
					int ny = dy[i] + pos.y;
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						if (map[ny][nx] != 0 && map[ny][nx] != conNum) {
							return res;
						}
						else if (map[ny][nx] == 0 && visit[ny][nx] == 0) {
							visit[ny][nx] = 1;
							q.offer(new Pair(ny, nx));
						}
					}
				}
			}
			res++;
		}
		return res;
	}

}
