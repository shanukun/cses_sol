import java.io.*;
import java.util.*; 


class PR {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] alp = new int[26];
        for (int i = 0; i < s.length(); i++) {
            alp[s.charAt(i) - 'A']++;
        }
        int oddCnt = 0;
        for (int i = 0; i < 26; i++) {
            if (alp[i] % 2 != 0) oddCnt++;
        }
        if (oddCnt > 1) {
            System.out.println("NO SOLUTION");
        } else {
            StringBuilder a = new StringBuilder("");
            StringBuilder b = new StringBuilder("");
            StringBuilder o = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                if (alp[i] == 0) continue;


                StringBuilder t = new StringBuilder("");
                if (alp[i] % 2 == 0) {
                    for (int j = 0; j < alp[i] / 2; j++) {
                        t.append((char) ('A' + i));
                    }
                } else {
                    for (int j = 0; j < alp[i]; j++) {
                        o.append((char) ('A' + i));
                    }
                   
                }
                a.append(t);
                t.append(b);
                b = t;
            }
            a.append(o);
            a.append(b);
            System.out.println(a);
        }
    }
}
