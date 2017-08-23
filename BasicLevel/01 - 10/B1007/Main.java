package bl1007;

import java.util.Scanner;

public class Main {
	static boolean[] isComposite;
	static int size;
	static int[] primes = new int[100005];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		size = init(N);
		int ret = 0;
		for (int i = 2; i < size; i++) {
			if (primes[i] - primes[i-1] == 2) ret++;
		}
		System.out.println(ret);
	}

	static int init(int N) {
		isComposite = new boolean[N + 1];
		int upperBound = (int)Math.sqrt(N);
		
		for (int i = 2; i <= upperBound; i++) {
			if (!isComposite[i]) {
				for (int j = i * i; j <= N; j += i) {
					isComposite[j] = true;
				}
			}
		}
		
		int m = 0;
		for (int i = 2; i <= N; i++) {
			if (!isComposite[i]) {
				primes[m++] = i;
			}
		}
		
		return m;
	}
}
