package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Vector;

public class baek4198 {

	/*
	 * 백준 4198 열차정렬
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = Integer.parseInt(br.readLine());
		}
		
		int[] lis = new int[n];
		int[] lds = new int[n];
		Vector<Integer> lisV = new Vector<Integer>();
		Vector<Integer> ldsV = new Vector<Integer>();

		for (int idx = 0; idx < n; idx++) {
			lisV.add(t[idx]); // t[idx]가 lis 최솟값 (기준 오른쪽으로 들어갈 것)
			ldsV.add(t[idx]);// t[idx]가 lds 최솟값 (기준열차 왼쪽으로 들어갈 것)
			for (int i = idx+1; i < n; i++) {
				// lis 검사
				if (t[i] > lisV.lastElement())
					lisV.add(t[i]);
				else if (t[i] > lisV.firstElement()) {
					for (int j = 2; j < lisV.size(); j++) {
						if (t[i] < lisV.elementAt(j)) {
							lisV.remove(j);
							lisV.add(j, t[i]);
							break;
						}
					}
				}
				// lds 검사
				if(t[i]<ldsV.lastElement())
					ldsV.add(t[i]);
				else if(t[i]<ldsV.firstElement()){
					for (int j = 2; j < ldsV.size(); j++) {
						if (t[i] > ldsV.elementAt(j)) {
							ldsV.remove(j);
							ldsV.add(j, t[i]);
							break;
						}
					}
				}
			
			}
			lis[idx]=lisV.size();
			lisV.clear();
			lds[idx]=ldsV.size();
			ldsV.clear();
		}
		int max=0;
		if(n!=0)
			max=lis[0]+lds[0]-1;
		
		for(int i=1;i<n;i++) {
			max=Math.max(max, lis[i]+lds[i]-1);
		}
		bw.write(Integer.toString(max));
		bw.flush();
		bw.close();
		br.close();
	}

}
