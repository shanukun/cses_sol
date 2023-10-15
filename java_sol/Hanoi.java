import java.io.*;
import java.util.*; 
import java.math.*; 

public class Hanoi {
    static List<int[]> moves;
    static void toh(int n, int to, int from, int mid) {
        if (n <= 0) return;
        toh(n - 1, to, mid, from);
        moves.add(new int[]{to, from});
        toh(n - 1, mid, from, to);
    }
    public static void main(String[] args) {
        moves = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int nd = sc.nextInt();

        toh(nd, 1, 3, 2);
        System.out.println(moves.size());
        for (int[] a: moves) {
            System.out.println(a[0] + " " + a[1]);
        }
    }
}
