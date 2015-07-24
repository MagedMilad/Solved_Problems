import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			int n = in.nextInt();
			int a = in.nextInt();
			BigInteger sum = BigInteger.ZERO;
			for (int i = 1; i <= n; i++)
				sum = sum.add(BigInteger.valueOf(i).multiply(
						BigInteger.valueOf(a).pow(i)));
			System.out.println(sum);
		}
		in.close();
	}

}
