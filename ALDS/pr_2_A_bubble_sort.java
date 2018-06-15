import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayDeque;
import java.util.Deque;

public class pr_2_A_bubble_sort {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String tmp_arr[] = new String[n];
		int arr[] = new int[n];
		tmp_arr = br.readLine().split(" ");
		// System.out.println(tmp_arr);
		for(int i=0; i<n;i++){
			arr[i] = Integer.parseInt(tmp_arr[i]);
		}
		
		bubblesort_swap_num(arr);
	}
	public static void bubblesort_swap_num(int[] arr){
		int n = arr.length;
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=1; j<n-i; j++){
				if(arr[j-1] > arr[j]){
					int tmp = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = tmp;
					ans++;
				}
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
