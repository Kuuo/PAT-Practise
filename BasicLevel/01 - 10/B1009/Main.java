import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String[] words = in.nextLine().split(" ");
        int len = words.length;
        for (int i = len - 1; i > -1; i--) {
            if (i != len - 1) System.out.print(" ");
            System.out.print(words[i]);
        }
  }

}