import java.util.Scanner;

import jdk.nashorn.internal.runtime.FindProperty;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        int target=sc.nextInt();
        int [][] a=new int[m][n];
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                    a[i][j]=sc.nextInt();
            }
        }
        boolean res=Find(target,a);
        System.out.println(res);
        sc.close();

    }
    public static boolean Find(int target, int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;
        int rows = matrix.length, cols = matrix[0].length;
        int r = 0, c = cols - 1; // 从右上角开始
        while (r <= rows - 1 && c >= 0) {
            if (target == matrix[r][c])
                return true;
            else if (target > matrix[r][c])
                r++;
            else
                c--;
        }
        return false;
    }
}
