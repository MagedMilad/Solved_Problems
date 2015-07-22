import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		while(true){
			BigInteger num = sc.nextBigInteger();
			if(num.equals(BigInteger.ZERO))
				break;
			sum = sum.add(num);
		}
		sc.close();
		System.out.println(sum);
	}
}
