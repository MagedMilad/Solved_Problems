import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Solver {

	public static BigInteger dp[][] = new BigInteger[1510][1510];

	public static BigInteger solve(int n, int p) {
		if (n <= 0 || p <= 0)
			return BigInteger.ZERO;
		if (dp[n][p] != null)
			return dp[n][p];
		if (n == p)
			return BigInteger.ONE;
		if (p > n)
			return BigInteger.ZERO;
		if (p == 1)
			return BigInteger.ONE;
		dp[n][p] = solve(n - 1, p - 1).add(solve(n - p, p));
		return dp[n][p];
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("sweets.in"));
		PrintWriter out = new PrintWriter("sweets.out");
		String[] s = in.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int p = Integer.parseInt(s[1]);
		out.print(solve(n, p).toString());
		in.close();
		out.close();
	}
}
