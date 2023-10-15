import java.io.*;
import java.util.*;

public class Aps {
    static class FastR {
        BufferedReader br;
        StringTokenizer st;
        public FastR() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch(IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        void print(long v) {
            System.out.println(v);
        }
    }
    static void sort(int[] a) {
        ArrayList<Integer> al = new ArrayList<>();
        for (int x: a) al.add(x);
        Collections.sort(al);
        int i = 0;
        for (int x: al) a[i++] = x;
    }
    public static void main(String[] args) {
        FastR fr = new FastR();
        int n = fr.nextInt();
        int m = fr.nextInt();
        int x = fr.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];

        for (int i = 0; i < n; i++)
            a[i] = fr.nextInt();
        for (int i = 0; i < m; i++)
            b[i] = fr.nextInt();
        sort(a);
        sort(b);
        long cnt = 0;
        for (int i = 0, j = 0; i < n && j < m;) {
            if (b[j] - x <= a[i] && b[j] + x >= a[i]) {
                ++i; ++j;
                ++cnt;
            } else if (a[i] < b[j] - x) {
                ++i;
            } else if (a[i] > b[j] + x) {
                ++j;
            }
        }
        fr.print(cnt);


    }
}
