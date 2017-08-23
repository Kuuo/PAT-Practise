package bl1003;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numOfStr = in.nextInt();
		in.nextLine();

		String patStr;
		for (int i = 0; i < numOfStr; i++) {
			patStr = in.nextLine();
			int indexOfP = -1;
			int indexOfT = -1;
			boolean containsOther = false;
			boolean isValid = false;
			int cntP = 0;
			int cntT = 0;
			int cntA = 0;

			char curCh;
			for (int j = 0; j < patStr.length(); j++) {
				curCh = patStr.charAt(j);

				if (curCh == 'P') {
					cntP++;
					if (indexOfP == -1)
						indexOfP = j;
				} else if (curCh == 'T') {
					cntT++;
					if (indexOfT == -1)
						indexOfT = j;
				} else if (curCh == 'A') {
					cntA++;
				} else {
					containsOther = true;
					break;
				}
			}

			if (cntP == 1 && cntT == 1 && cntA > 0 && !containsOther) {
				int cntA1 = indexOfP;
				int cntA2 = indexOfT - indexOfP - 1;
				int cntA3 = patStr.length() - indexOfT - 1;
				if (cntA1 * cntA2 == cntA3)
					isValid = true;
			}

			System.out.println(isValid ? "YES" : "NO");
		}

		in.close();
	}
}
