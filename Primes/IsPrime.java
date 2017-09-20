import java.math.BigInteger;
import java.util.Scanner;
public class prime {
	public static void main(String[] args) {
		BigInteger a = new BigInteger("1299827");
		//User miller rabin & Lucas Lehmer
		boolean res = a.isProbablePrime(10);
		System.out.println(res? "It's prime":"It's not prime");
	}
}
