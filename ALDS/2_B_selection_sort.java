import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class pr_2_B_selection_sort {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String tmp_arr[] = new String[n];
		int arr[] = new int[n];
		tmp_arr = br.readLine().split(" ");
		for(int i=0; i<n; i++){
			arr[i] = Integer.parseInt(tmp_arr[i]);
		}
		selection_sort(arr);
	}
	
	public static void selection_sort(int[] arr){
		int ans = 0;
		for(int i=0; i<arr.length; i++){
			int min_ix = i;
			for(int j=i; j<arr.length; j++){
				if(arr[min_ix] > arr[j]) min_ix = j;
			}
			if(min_ix != i){
				// swap
				int tmp = arr[min_ix];
				arr[min_ix] = arr[i];
				arr[i] = tmp;
				ans++;
			}
		}
		print_array(arr);
		System.out.println(ans);
	}
	public static void print_array(int[] arr){
		for(int i=0; i<arr.length; i++){
			System.out.print(arr[i]);
			if(i != arr.length-1) System.out.print(" ");
			else System.out.print("\n");
		}
	}


}
