import java.util.*;
public class BOJ_2577 {
    public static void main(String[] args){
        int[] cnt = new int[10];
        Scanner s = new Scanner(System.in);

        long result = 1;
        for (int i = 0; i < 3; i++)
            result = result * s.nextInt();

        for (char a:
            Long.toString(result).toCharArray()) {
            cnt[(int)a - 48] += 1;
        }

        for (int i:
             cnt) {
            System.out.println(i);
        }
    }
}
