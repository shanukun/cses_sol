import java.io.*;
import java.util.*;
import java.math.*;

public class NumSpiral {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
    public static void main(String[] args) {
        FastReader sc = new FastReader();

        long t = sc.nextLong();
        while (t-- > 0) {
            long x = sc.nextLong() - 1;
            long y = sc.nextLong() - 1;
            long tot;
            if (y > x) {
                if (y % 2 != 0) {
                    tot = y * y + 1;
                } else {
                    tot = (y + 1) * (y + 1);
                    x = -x;
                }
                System.out.println(tot + x);
            } else {
                if (x % 2 == 0) {
                    tot = x * x + 1;
                } else {
                    tot = (x + 1) * (x + 1);
                    y = -y;
                }
                System.out.println(tot + y);
            }
        }
    }
}
