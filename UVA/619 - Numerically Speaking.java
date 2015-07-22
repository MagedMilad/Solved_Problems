import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			String line = in.nextLine();
			if (line.equals("*"))
				break;
			String num, word;
			if (line.charAt(0) >= '0' && line.charAt(0) <= '9') {
				num = line;
				word = numToString(new BigInteger(line));
			} else {
				word = line;
				num = stringToNum(line).toString();
			}
			System.out.printf("%-22s", word);
			int comma = num.length();
			for (int i = 0; i < num.length(); i++) {
				if (comma % 3 == 0 && i != 0)
					System.out.print(',');
				System.out.print(num.charAt(i));
				comma--;
			}
			System.out.println();
		}
		in.close();
	}

	static BigInteger stringToNum(String line) {
		BigInteger res = BigInteger.ZERO;
		BigInteger temp = BigInteger.ONE;
		for (int i = line.length() - 1; i >= 0; i--) {
			res = res
					.add(temp.multiply(BigInteger.valueOf(line.charAt(i) - 'a' + 1)));
			temp = temp.multiply(BigInteger.valueOf(26));
		}
		return res;
	}

	static String numToString(BigInteger num) {
		StringBuffer sb = new StringBuffer("");
		while (num.compareTo(BigInteger.ZERO) > 0) {
			BigInteger mod = num.mod(BigInteger.valueOf(26));
			num = num.divide(BigInteger.valueOf(26));
			char c = (char) (mod.intValue() + 96);
			sb.append(c);
		}
		return sb.reverse().toString();
	}
}
