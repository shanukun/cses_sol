import java.io.*;
import java.util.*;
import java.math.*;

public class Repetitions {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        int ans = 1;
        int j = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(j)) {
                ans = Math.max(i - j + 1, ans);
            } else {
                j = i;
            }
        }
        System.out.println(ans);
    }
}

