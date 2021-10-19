import java.util.Arrays;
public class CyclicSort{
    public static void main(String args[]){
        int[] arr={3,5,2,1,4};//it can be 0 to N-1 but it needs to be continuous
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
        static void sort(int[] arr){
            int i=0;
            while(i<arr.length){
                int correct =arr[i]-1; //N-1 logic
                if(arr[i]!=arr[correct]){
                    swap(arr,i,correct);
                }
                else{
                    i++;
                }
            }
        }
  static void swap(int[] arr,int first, int second){
            int temp= arr[first];
            arr[first]=arr[second];
            arr[second]=temp;
        }
}

/*
output:
[1, 2, 3, 4, 5]
*/
