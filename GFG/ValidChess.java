/*Given a NXN chessboard. The task is to check if the given chessboard is valid or not. 
 *A chess board is considered valid if every 2 adjacent cells are painted with different color. 
 *Two cells are considered adjacent if they share a boundary.*/
import java.io.*;
class ValidChess{
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    public static void main()throws IOException{
        System.out.print("Enter the number of rows:");
        int n=Integer.parseInt(br.readLine());
        int a[][]=new int[n][n];
        inputBoard(a,n);
        displayBoard(a,n);
        System.out.println(isValid(a,n)?"Yes":"No");
    } 
    static void inputBoard(int a[][],int n)throws IOException{
        System.out.println("Enter the elements in chess rowwise(0 or 1)");
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=Integer.parseInt(br.readLine());
    }
    static void displayBoard(int a[][],int n){
        System.out.println("Chess Board:");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(a[i][j]+" ");
            System.out.println();
        }
    }
    static boolean isValid(int a[][], int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%2==0 && a[i][j]!=a[0][0])  return false;
                if((i+j)%2!=0 && a[i][j]==a[0][0])  return false;
            }
        }
        return true;
    }
    /* Alternate method*/
    /* static boolean isValid(int a[][],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)    continue;
                if(j==0){
                    if(a[i][j]==a[i-1][j])
                        return false;
                }
                else if(a[i][j]==a[i][j-1])  
                    return false;
            }
        }
        return true;
    }*/
}
