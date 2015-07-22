import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			a = a.multiply(b);
			System.out.println(a);
		}
		in.close();
	}
}
