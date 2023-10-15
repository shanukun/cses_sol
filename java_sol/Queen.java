import java.io.*;
import java.util.*; 
import java.math.*; 

public class Queen {
    static boolean[] c, d1, d2;
    static int cnt;
    static void pq(String[] sa, int i) {
        if (i >= 8) {
            cnt++;
        }

        for (int j = 0; j < 8; ++j) {
            if (c[j] || d1[i + j] || d2[i + 7 - j] || sa[i].charAt(j) == '*') continue;
            c[j] = d1[i + j] = d2[i + 7 - j] = true;
            pq(sa, i + 1);
            c[j] = d1[i + j] = d2[i + 7 - j] = false;
        }
    } 
    public static void main(String[] args) {
        c = new boolean[8];
        d1 = new boolean[15];
        d2 = new boolean[15];
        cnt = 0;

        Scanner sc = new Scanner(System.in);
        String[] sa = new String[8];
        for (int i = 0; i < 8; i++)
            sa[i] = sc.nextLine();
        pq(sa, 0);

        System.out.println(cnt);
    }
}
