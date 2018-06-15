import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayDeque;
import java.util.Deque;

public class pr_3_C_double_linked_list {
    public static void main(String[] args) throws IOException{
        // Prints "Hello, World" to the terminal window.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n = Integer.parseInt(br.readLine());
    	int i = 0;
    	String orders[] = new String[n];
    	Deque<String> doubly_linked_list = new ArrayDeque<String>();
    	StringBuilder ans = new StringBuilder();
    	
    	while(i++ < n){
    		String order_word[] = new String[2]; 
    		order_word = br.readLine().split(" ");
    		System.out.println(order_word);
    		String order = order_word[0];
    		String num = order_word[1];
    		
    		if(order.equals("insert")){
    			doubly_linked_list.addFirst(num);
    		}
    		if(order.equals("delete")){
    			doubly_linked_list.remove(num);
    		}
    		if(order.equals("deleteFirst")){
    			doubly_linked_list.removeFirst();
    		}
    		if(order.equals("deleteLast")){
    			doubly_linked_list.removeLast();
    		}
    	}    		
		if(!doubly_linked_list.isEmpty()){
			ans.append(doubly_linked_list.getFirst());
			doubly_linked_list.removeFirst();
		}
		
		while(!doubly_linked_list.isEmpty()){
			ans.append(" ").append(doubly_linked_list.getFirst());
			doubly_linked_list.removeFirst();
		}
		System.out.println(ans.toString());
    }
}    
