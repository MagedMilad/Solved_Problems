import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("toral.in"));
		PrintWriter out = new PrintWriter("toral.out");
		String[] s = in.readLine().split(" ");
		BigInteger n = new BigInteger(s[0]);
		BigInteger m = new BigInteger(s[1]);
		out.print(n.gcd(m).toString());
		in.close();
		out.close();
	}
}
