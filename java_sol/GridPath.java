import java.io.*;

public class GridPath {
    static boolean[][] grid;
    static int cnt;
    static boolean e(int i, int j) {
        return i>=0 && i<7 && j >= 0 && j < 7 && grid[i][j] == false;
    }
    static void dfs(String q, int k, int i, int j) {
        if (i == 6 && j == 0) {
            if (k == 48) 
                ++cnt;
            return;
        }
        if (k >= 48) {
            return;
        }
        int cnt = 0;
        grid[i][j] = true;
        char c = q.charAt(k);
        if (c == '?' || c == 'D') {
            if (e(i + 1, j)) {
                if (!(!e(i + 2, j) && e(i + 1, j + 1) && e(i + 1, j - 1)))
                    dfs(q, k + 1, i + 1, j);
            }
        }
        if (c == '?' || c == 'R') {
            if (e(i, j + 1)) {
                if (!(!e(i, j + 2) && e(i + 1, j + 1) && e(i - 1, j + 1))) 
                    dfs(q, k + 1, i, j + 1);
            }
        }
        if (c == '?' || c == 'L') {
            if (e(i, j - 1)) {
                if (!(!e(i, j - 2) && e(i + 1, j - 1) && e(i - 1, j - 1)))
                    dfs(q, k + 1, i, j - 1);
            }
        }
        if (c == '?' || c == 'U') {
            if (e(i - 1, j)) {
                if (!(!e(i - 2, j) && e(i - 1, j - 1) && e(i - 1, j + 1)))
                    dfs(q, k + 1, i - 1, j );
            }
        }
        grid[i][j] = false;
    }
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String q = "";
        try {
            q = br.readLine();
        } catch(IOException e) {

        }
        grid = new boolean[7][7];

        dfs(q, 0, 0, 0);

        System.out.println(cnt);
    }
}
