import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Solver {

	public static int log_base_2(BigInteger num) {
		if (num.getLowestSetBit() == num.bitLength() - 1)
			return num.bitLength() - 1;
		return num.bitLength();
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("puzzle.in"));
		PrintWriter out = new PrintWriter("puzzle.out");
		String[] s = in.readLine().split(" ");
		BigInteger[] a = new BigInteger[3];
		a[0] = new BigInteger(s[0]);
		a[1] = new BigInteger(s[1]);
		a[2] = new BigInteger(s[2]);
		int res = log_base_2(a[0]) + log_base_2(a[1]) + log_base_2(a[2]);
		out.print(res);
		in.close();
		out.close();
	}
}
