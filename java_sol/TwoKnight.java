import java.io.*;
import java.util.*;

public class TwoKnight {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        for (int i = 1; i <= n; i++) {
            long k = i * i;
            long x = (k * (k - 1)) / 2;
            long y = 0;
            if (i > 2) {
                y = 4 * (i - 1) * (i - 2);
            }
            System.out.println(x - y);
        }
    }
}
