import java.io.*;
import java.util.*;

public class MissingNum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] nums = new int[n + 1];
        for (int i = 0; i < n - 1; i++) {
            nums[sc.nextInt()] = 1; 
        }
        for (int i = 1; i <= n; i++) {
            if (nums[i] != 1) {
                System.out.println(i);
                break;
            }
        }
    }
}
