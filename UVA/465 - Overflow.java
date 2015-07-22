import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String s = in.nextLine();
			System.out.println(s);
			s = s.replace(" ", "");
			int idx = s.indexOf('+');
			BigInteger a, b, c;
			if (idx >= 0) {
				a = new BigInteger(s.substring(0, idx));
				b = new BigInteger(s.substring(idx + 1, s.length()));
				c = a.add(b);
			} else {
				idx = s.indexOf('*');
				a = new BigInteger(s.substring(0, idx));
				b = new BigInteger(s.substring(idx + 1, s.length()));
				c = a.multiply(b);
			}
			if(a.compareTo(new BigInteger(""+2147483647))>0)
				System.out.println("first number too big");
			if(b.compareTo(new BigInteger(""+2147483647))>0)
				System.out.println("second number too big");
			if( c.compareTo( new BigInteger( "" + 2147483647 )) > 0)
				System.out.println("result too big");
		}
		in.close();
	}
}
