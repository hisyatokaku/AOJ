import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class pr_2_C_is_stable_sort {
	
	public static <E> void print_array(E[] arr){
		int i=0;
		for(E element: arr){
			System.out.print(element);
			if(i != arr.length-1) System.out.print(" ");
			else System.out.print("\n");
			i++;
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String tmp_arr[] = new String[n];
		tmp_arr = br.readLine().split(" ");
		String tmp_arr1[] = new String[n];
		String base_arr[] = new String[n];
		
		// srcPos: beginning in tmp_arr, destPos: beginning in tmp_arr1
		System.arraycopy(tmp_arr, 0, base_arr, 0, n);		
		System.arraycopy(tmp_arr, 0, tmp_arr1, 0, n);
		
		String[] bubbled_arr = bubblesort(tmp_arr);
		print_array(bubbled_arr);
		if(check_stable(bubbled_arr, base_arr)) System.out.println("Stable");
		else System.out.println("Not stable");
		String[] selected_arr = selectionsort(tmp_arr1);
		print_array(selected_arr);
		if(check_stable(selected_arr, base_arr)) System.out.println("Stable"); 		
		else System.out.println("Not stable");

	}	
	
	public static String[] bubblesort(String[] arr){
		int n = arr.length;
		for(int i=0; i<n; i++){
			for(int j=1; j<n-i; j++){
				if(Character.getNumericValue(arr[j-1].charAt(1)) > Character.getNumericValue((arr[j].charAt(1)))){
					String tmp = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = tmp;
				}
			}
		}		
		return arr;
	}
	
	public static String[] selectionsort(String[] arr){
		for(int i=0; i<arr.length; i++){
			int min_ix = i;
			for(int j=i; j<arr.length; j++){
				if(Character.getNumericValue(arr[min_ix].charAt(1)) > Character.getNumericValue(arr[j].charAt(1))) min_ix = j;
			}
			if(min_ix != i){
				// swap
				String tmp = arr[min_ix];
				arr[min_ix] = arr[i];
				arr[i] = tmp;
			}
		}
		return arr;
	}
	public static boolean check_stable(String[] arr, String[] sorted_arr){
		int n = arr.length;
		for(int checknum=1; checknum<10; checknum++){
			String[] check_bff_1 = new String[n];
			String[] check_bff_2 = new String[n];
			
			int bff_ix_1 = 0;
			int bff_ix_2 = 0;
			
			for(int i=0; i<n; i++){
				if (Character.getNumericValue(sorted_arr[i].charAt(1)) == checknum){
					check_bff_1[bff_ix_1] = sorted_arr[i];
					bff_ix_1++;
				}
				if (Character.getNumericValue(arr[i].charAt(1)) == checknum){
					check_bff_2[bff_ix_2] = arr[i];
					bff_ix_2++;
				}
			}
			for(int j=0; j<n; j++){
				if(check_bff_1[j] == null && check_bff_2[j] == null) continue;
				if(check_bff_1[j] != check_bff_2[j]) return false;
			}
		}
		return true;
	}
}
		