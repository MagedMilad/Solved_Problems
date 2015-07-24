import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tc = 0;
		while (true) {
			tc++;
			int n, f;
			n = in.nextInt();
			f = in.nextInt();
			if (n == 0 && f == 0)
				break;
			BigInteger sum = BigInteger.ZERO;
			for (int i = 0; i < n; i++) {
				sum = sum.add(in.nextBigInteger());
			}
			System.out.println("Bill #" + tc + " costs " + sum
					+ ": each friend should pay "
					+ sum.divide(BigInteger.valueOf(f)) + "\n");
		}
		in.close();
	}

}
