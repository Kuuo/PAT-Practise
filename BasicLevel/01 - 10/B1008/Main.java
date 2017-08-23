package bl1008;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		int[] num = new int[N];
		for (int i = 0; i < N; i++) {
			num[i] = in.nextInt();
		}
		
		for (int i = N - M; i < N; i++) {
			System.out.print(num[i] + " ");
		}
		
		for (int i = 0; i < N - M; i++) {
			System.out.print(num[i]);
			if (i != (N - M - 1)) System.out.print(" ");
		}
	}

}
