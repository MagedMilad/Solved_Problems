import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		while(tc-->0){
			StringBuffer sb = new StringBuffer(in.next());
			BigInteger a = new BigInteger(sb.reverse().toString());
			sb = new StringBuffer(in.next());
			BigInteger b = new BigInteger(sb.reverse().toString());
			a = a.add(b);
			sb = new StringBuffer(a.toString()).reverse();
			a = new BigInteger(sb.toString());
			System.out.println(a);
		}
		in.close();
	}
}
