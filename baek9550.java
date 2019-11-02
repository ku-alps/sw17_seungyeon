package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek9550 {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb=new StringBuilder();
		
		int T=Integer.parseInt(br.readLine());
		for(int i=0;i<T;i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken());
			int K=Integer.parseInt(st.nextToken());
			int[] c=new int[N];
			st=new StringTokenizer(br.readLine());
			int count=0;
			for(int j=0;j<N;j++) {
				c[j]=Integer.parseInt(st.nextToken());
				count+=c[j]/K; //사탕 종류별로 부를 수 있는 아이 명수 구하기
			}
			sb.append(count);
			 if (i<T-1)
				 sb.append("\n");
		}
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

}
