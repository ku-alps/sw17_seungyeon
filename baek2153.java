package algorithmStudy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class baek2153 {
/*
 * 백준 2153 소수단어
 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String isPrime="It is a prime word.";
		String isNotPrime="It is not a prime word.";
		
		String str=br.readLine();
		int sum=0;
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)>='a' && str.charAt(i)<='z')
				sum+=str.charAt(i)-'a'+1;
			else
				sum+=str.charAt(i)-'A'+27;
		}
		
		boolean flag=true;
		for(int i=2;i<sum;i++) {
			if(sum%i==0) {
				flag=false;
				bw.write(isNotPrime);
				break;
			}
		}
		if(flag)
			bw.write(isPrime);
		bw.flush();
		br.close();
		bw.close();
	}

}
