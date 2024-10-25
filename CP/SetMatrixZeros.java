package Java_DSA.Problems.Matrix;
import java.io.*;
import java.util.* ;

public class SetMatrixZeros {
    public static void setZeros(int[][] matrix) {
        // Write your code here..

        // int m=matrix.length, n=matrix[0].length;
        // boolean isRow0=false, isCol0=false;

        // for(int j=0;j<n;j++){
        //     if(matrix[0][j]==0)
        //         isRow0=true;
        // }

        // for(int i=0;i<m;i++){
        //     if(matrix[i][0]==0)
        //         isCol0=true;
        // }

        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         if(matrix[i][j]==0){
        //             matrix[i][0]=0;
        //             matrix[0][j]=0;
        //         }
        //     }
        // }

        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         if(matrix[0][j]==0 || matrix[i][0]==0)
        //             matrix[i][j]=0;
        //     }
        // }

        // if(isRow0){
        //     for(int j=0;j<n;j++)
        //         matrix[0][j]=0;
        // }

        // if(isCol0){
        //     for(int i=0;i<m;i++)
        //         matrix[i][0]=0;
        // }
        int m=matrix.length, n=matrix[0].length;
        int[] rowsArray = new int[m];
        int[] colsArray = new int[n];

        Arrays.fill(rowsArray,1);
        Arrays.fill(colsArray,1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowsArray[i]=0;
                    colsArray[j]=0;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowsArray[i]==0 || colsArray[j]==0)
                    matrix[i][j]=0;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {{4,2,3}
                         ,{1,0,3}
                         ,{1,2,3}};
        setZeros(matrix);

        for(int i = 0;i < matrix.length;i++){
            for(int j = 0;j < matrix[0].length;j++){
                System.out.print(matrix[i][j]+ " ");
            }
            System.out.println();
        }

//            for (int[] element : matrix) {
//            for (int j = 0; j < matrix[0].length; j++) {
//                System.out.print(element[j] + " ");
//            }
//            System.out.println();
//        }
    }
}
