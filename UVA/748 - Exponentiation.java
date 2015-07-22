import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			BigDecimal a = in.nextBigDecimal();
			int b = in.nextInt();
			a = a.pow(b);
			String res = a.stripTrailingZeros().toPlainString();
			if (res.charAt(0) == '0')
				res = res.substring(1, res.length());
			System.out.println(res);
		}
		in.close();
	}
}
