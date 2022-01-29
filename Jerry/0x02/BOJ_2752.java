import java.util.*;
public class BOJ_2752{
    public static void main(String[] args){
        int[] a = new int[3];
        Scanner s = new Scanner(System.in);
        a[0] = s.nextInt();
        a[1] = s.nextInt();
        a[2] = s.nextInt();
        Arrays.sort(a);
        for(int i : a){
            System.out.print(i+" ");
        };
    }
}
