import java.io.*;
import java.util.*; 

public class CreateString {
    static TreeSet<String> hs;
    static void perm(StringBuilder s, int ind) {
        hs.add(s.toString());
        if (ind >= s.length()) {
            return;
        }
        for (int i = ind; i < s.length(); i++) {
            char a = s.charAt(ind);
            char b = s.charAt(i);
            s.setCharAt(ind, b);
            s.setCharAt(i, a);
            perm(s, ind + 1);
            s.setCharAt(ind, a);
            s.setCharAt(i, b);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        hs = new TreeSet<>();
        StringBuilder sb = new StringBuilder(s);
        perm(sb, 0);
        System.out.println(hs.size());
        for (String sr: hs) 
            System.out.println(sr);
    }
}
