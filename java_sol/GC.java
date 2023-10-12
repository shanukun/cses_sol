import java.io.*;
import java.util.*; 


class GC {
    static void print(List<String> l) {
        for (String s: l) {
            System.out.println(s);
        }
    }
    public static void main(String[] args) {
        List<String> a = new ArrayList<>();
        a.add("0");
        a.add("1");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n - 1; i++) {
            List<String> b = new ArrayList<>();
            for (String s: a) {
                b.add(s);
            }
            while (!a.isEmpty()) {
                b.add(a.get(a.size() - 1));
                a.remove(a.size() - 1);
            }
            String c = "0";
            for (int j = 0; j < b.size(); j++) {
                if (j >= b.size() / 2) 
                    c = "1";

                b.set(j, c + b.get(j));
            }
            a = new ArrayList<>(b);
        }
        print(a);
    }
}
