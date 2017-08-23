package bl1001;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.close();
		
		int cnt = 0;
		
		while (num != 1) {
			if ((num & 1) == 1) {
				num = (3 * num + 1) >> 1;
			} else {
				num = num >> 1;
			}
			cnt++;
		}

		System.out.println(cnt);
	}

}
