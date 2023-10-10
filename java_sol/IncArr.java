import java.io.*;
import java.util.*;
import java.math.*;

public class IncArr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];
        long ans = 0l;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                ans += arr[i - 1] - arr[i];
                arr[i] = arr[i - 1];
            }
        }
        System.out.println(ans);
    }
}

