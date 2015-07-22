import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String line = in.nextLine();
			line = line.replace(" ", "");
			int idx = line.indexOf('/');
			if (idx >= 0) {
				BigInteger a = new BigInteger(line.substring(0, idx));
				BigInteger b = new BigInteger(line.substring(idx + 1,
						line.length()));
				a = a.divide(b);
				System.out.println(a);
			} else {
				idx = line.indexOf('%');
				BigInteger a = new BigInteger(line.substring(0, idx));
				BigInteger b = new BigInteger(line.substring(idx + 1,
						line.length()));
				a = a.mod(b);
				System.out.println(a);
			}
		}
		in.close();
	}
}
