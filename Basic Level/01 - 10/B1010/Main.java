import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int a = 0, b = 0;
        int flag = 0;

        while (in.hasNext()) {
            a = in.nextInt();
            b = in.nextInt();

            if (flag == 0) {
                if (b == 0) {
                    System.out.print("0 0");
                    return;
                }
            }

            if (b != 0) {
                if (flag != 0) {
                    System.out.print(" ");
                }
                flag = 1;
                System.out.print((a * b) + " " + (b - 1));
            }
        }
    }
}