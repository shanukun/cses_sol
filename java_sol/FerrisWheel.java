import java.io.*;
import java.util.*;

public class FerrisWheel {
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
        void print(int v) {
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
        int x = fr.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = fr.nextInt();
        sort(a);
        int i = 0, j = n - 1;
        int cnt = 0;
        while (i <= j) {
            if (i == j) {cnt++; break;}
            if (a[i] + a[j] > x) {
                j--;
                cnt++;
            } else {
                i++;
                j--;
                cnt++;
            }
        }
        fr.print(cnt);
    }
}
