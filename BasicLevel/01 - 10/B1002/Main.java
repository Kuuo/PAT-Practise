package bl1002;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String numStr = in.nextLine();
		in.close();

		int sum = 0;
		for (int i = 0; i < numStr.length(); i++) {
			sum += numStr.charAt(i) - '0';
		}

		String[] numpy = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi",
				"ba", "jiu" };
		
		String sumStr = sum + "";
		for (int i = 0; i < sumStr.length(); i++) {
			if (i != 0) System.out.print(" ");
			System.out.print(numpy[(sumStr.charAt(i) - '0')]);
		}
	}
}
