package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.Vector;

public class baek2846 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N=Integer.parseInt(br.readLine());
		int[] r=new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			r[i] = Integer.parseInt(st.nextToken());
		}
		int max=0;
		Vector<Integer> v=new Vector<Integer>();
		v.add(r[0]);
		for(int i=1;i<N;i++) {
			if(r[i]>v.lastElement()) {
				v.add(r[i]);
			}
			else {
				v.clear();
				v.add(r[i]);
			}
			if(v.size()>1) {
				int dis=v.lastElement()-v.firstElement();
				if(dis>max)
					max=dis;
			}
		}
		bw.write(Integer.toString(max));
		bw.flush();
		bw.close();
		br.close();
	}

}
