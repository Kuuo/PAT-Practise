import java.util.*;

public class Main {

  public static void main(String[] args) {

    Scanner in = new Scanner(System.in);
    int num = in.nextInt();
    in.close();

    int cntB = num / 100;
    int cntS = num / 10 % 10;
    int cnt1 = num % 10;

    for (int i = 0; i < cntB; i++) {
        System.out.print("B");
    }
    for (int i = 0; i < cntS; i++) {
        System.out.print("S");
    }

    String digit = "123456789";
    System.out.print(digit.substring(0, cnt1));
  }
}