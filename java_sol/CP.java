import java.io.*;
import java.util.*; 


class CP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder print = new StringBuilder("");
        while (n-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            if (a < b)
                a = b + a - (b = a);

            if (a == 0 && b == 0)
                print.append("YES");
            else if (a == 0 || b == 0)
                print.append("NO");
            else if ((a + b) % 3 == 0 && (a / 2) <= b)
                print.append("YES");
            else
                print.append("NO");
            if (n > 0)
            print.append("\n");
        }
        System.out.println(print);
    }
}
