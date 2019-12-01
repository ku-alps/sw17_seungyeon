package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class baek1181 {
	// น้มุ 1181
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		List<String> wList = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			if(wList.contains(str)) continue;
			wList.add(str);
		}
		
		Collections.sort(wList,new Comparator<String>() {

			@Override
			public int compare(String o1, String o2) {
				// TODO Auto-generated method stub
				if (o1.length() > o2.length())
					return 1;
				else if (o1.length() < o2.length())
					return -1;
				else {
					return o1.compareTo(o2);
				}
			}
		
		});
		Collections.sort(wList);
		for(int i=0;i<wList.size();i++) {
			bw.write(wList.get(i)+"\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}



}
