import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int numOfSts = in.nextInt();
    in.nextLine();

    int maxScore = -1, minScore = 999;
    String maxStr = "", minStr = "";
    for (int i = 0; i < numOfSts; i++) {
        String si = in.nextLine();
        int curScore = Integer.parseInt(si.split(" ")[2]);

        if (curScore <= minScore) {
            minScore = curScore;
            minStr = si;
        }

        if (curScore >= maxScore) {
            maxScore = curScore;
            maxStr = si;
        }
    }
    in.close();

    String[] maxRet = maxStr.split(" ");
    String[] minRet = minStr.split(" ");
    System.out.println(maxRet[0] + " " + maxRet[1]);
    System.out.println(minRet[0] + " " + minRet[1]);
  }
}