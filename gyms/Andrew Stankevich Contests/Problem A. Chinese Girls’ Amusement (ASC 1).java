import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("china.in"));

        PrintWriter out = new PrintWriter("china.out");
        // Scanner in = new Scanner(System.in);
        BigInteger num = new BigInteger(br.readLine());
        BigInteger m = new BigInteger("2");
        BigInteger mid = num.mod(m);
        if (mid.equals(new BigInteger("1"))) {
            out.println(num.divide(new BigInteger("2")));
        } else {
            mid = num.divide(new BigInteger("2"));
            if ((mid.mod(new BigInteger("2"))).equals(new BigInteger("1"))) {
                out.println(mid.subtract(new BigInteger("2")));
            } else {
                out.println(mid.subtract(new BigInteger("1")));
            }
        }
        out.close();
    }
}