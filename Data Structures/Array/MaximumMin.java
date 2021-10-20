//Find the maximum and minimum element in array
public class MaximumMin{
    public static void main(String args[]){
        //Intializing the original array
        int arr[] = new int [] {19,44,77,-200,-50,33};
        int max=arr[0];
        int min=arr[0];

        for(int i=1;i<arr.length;i++){
            if(max<arr[i]){
                max=arr[i];
            }
            else if(min>arr[i]){
                min=arr[i];
            }
        }
        System.out.println("max no is: "+max+" min no is: "+min);
    }
}

//output:
//max no is 77 min no is -200
