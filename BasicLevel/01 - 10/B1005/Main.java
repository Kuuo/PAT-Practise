import java.util.*;

public class Main {

  public static void main(String[] args) {

    int[][] coverByi = new int[101][501];
    for (int i = 1; i < 101; i++) {
        int j = 0;
        int caled = i;
        while (caled != 1) {
            if ((caled & 1) == 1) {
                caled = (caled * 3 + 1) >> 1;
            } else {
                caled = caled >> 1;
            }
            coverByi[i][j++] = caled;
        }
    }


    Scanner in = new Scanner(System.in);
    int K = in.nextInt();
    in.nextLine();
    String[] onumstr = in.nextLine().split(" ");
    in.close();

    int[] onum = new int[K];
    for (int i = 0; i < K; i++) {
        onum[i] = Integer.parseInt(onumstr[i]);
    }
    Arrays.sort(onum);
    boolean[] isKey = new boolean[K];
    Arrays.fill(isKey, true);

    for (int i = 0; i < K; i++) {
        if (!isKey[i]) continue;
        int j = 0;
        while (coverByi[onum[i]][j] != 0) {
            int index = Arrays.binarySearch(onum, coverByi[onum[i]][j]);
            if (index >= 0 && index < K) {
                isKey[index] = false;
            }
            j++;
        }
    }


    int[] ret = new int[K];
    for (int i = 0, j = 0; i < K; i++) {
        if (isKey[i]) ret[j++] = onum[i];
    }

    Arrays.sort(ret);
    for (int i = K - 1; i > -1; i--) {
        if (ret[i] != 0) {
            if (i != K-1) System.out.print(" ");
            System.out.print(ret[i]);
        }
    }

  }
}