package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class baek9372 {
	/*
	 * 백준9372 상근이의 여행
	 * */
	public static int [][]g;
	public static int []v; //visited 국가 체크
	public static int n,m;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st; 
		
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++) {
			st= new StringTokenizer(br.readLine());
			n= Integer.parseInt(st.nextToken());
			m= Integer.parseInt(st.nextToken());
			g=new int[n][n];
			v=new int [n];
			for(int j=0;j<m;j++) {
				st= new StringTokenizer(br.readLine());
				int a= Integer.parseInt(st.nextToken());
				int b= Integer.parseInt(st.nextToken());
				g[a-1][b-1]=1;
				g[b-1][a-1]=1;
			}
			int cnt=search();
			bw.write(Integer.toString(cnt)+"\n");
		}
		
		bw.flush();
		br.close();
		bw.close();
	}
	public static int search() {
		Queue<Integer> q=new LinkedList<>(); //offer (push) , poll(pop)
		int cnt=0;
		q.offer(0);
		while(!q.isEmpty()) {
			int front=q.poll();
			for(int i=1;i<n;i++) {
				if(g[front][i]==1 && v[i]==0) {
					cnt++;
					v[i]=1;
					q.offer(i);
				}
			}
		}
		return cnt;
	}
}
