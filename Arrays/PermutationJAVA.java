public class Permutation{

    public static void main(String[] args){
        int[] array={3,5,0};
        permute(0, array);
    }

    public static void swap(int [] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void show(int[] input){
        for(int x: input){
            System.out.print(x);
        }
        System.out.println("");
    }

    public  static void permute(int start, int[] input ) {
        if (start == input.length) {
            show(input);
            return;
        }
        for (int i = start; i < input.length; i++) {
            swap(input, i, start);
            permute(start + 1, input);
            swap(input, i, start);
        }
    }

}
