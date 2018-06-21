import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;


public class pr_5_C_koch_curve {	
    public static void main(String[] args) throws IOException{
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int depth = Integer.parseInt(br.readLine());
		Point p1 = new Point();
		Point p2 = new Point();	
		p1.set_point(0, 0);
		p2.set_point(100, 0);
		print_points(middle_three(p1, p2, depth));
		System.out.printf("%f %f\n", p2.x, p2.y);
    }
    
    public static Point[] middle_three(Point p1, Point p2, int depth){
    	if(depth == 0){
    		Point[] new_arr = {p1}; 
    		return new_arr;
    	}
    	
    	// return s, u, t
    	// calculate length

    	// pq_u_tilde = devide p1-p2 by 2 : (2*sqrt(3)-2)
    	// rotate pq_u_tilde for +30 deg 
    	// return middle_three(p1, s, depth) + middle_three(s, u) + middle_three(u, t) + middle_three(t, p2)
    	// [s, u, t]
    	
    	double l = Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
    	Point s = new Point();
    	Point u_tilde = new Point();
    	//Point u = null;
    	Point t = new Point();
    	
    	s.set_point(inter_division(p1.x, p2.x, 1, 2), inter_division(p1.y, p2.y, 1, 2));
    	t.set_point(inter_division(p1.x, p2.x, 2, 1), inter_division(p1.y, p2.y, 2, 1));
    	
    	u_tilde.set_point(inter_division(p1.x, p2.x, 2, 2*Math.sqrt(3)-2), 
    					  inter_division(p1.y, p2.y, 2, 2*Math.sqrt(3)-2)
    			);
    	Point u = rotate_line(p1, u_tilde, 30);
    	Point[] new_arr = two_arr2one(
    							two_arr2one(
    								two_arr2one(middle_three(p1, s, depth-1), middle_three(s, u, depth-1)), 
    								middle_three(u, t, depth-1) 
    								), middle_three(t, p2, depth-1)
    							);
    	return new_arr;
    }
    
    private static double inter_division(double x1, double x2, double a, double b){
    	return (x1 * b + x2 * a)/(a+b);
    }
    
    private static Point rotate_line(Point p1, Point p2, double deg){
    	// rotate vec(x->y)
    	deg = Math.toRadians(deg);
    	double x_rotated = (p2.x - p1.x) * Math.cos(deg) - (p2.y - p1.y) * Math.sin(deg) + p1.x;
    	double y_rotated = (p2.x - p1.x) * Math.sin(deg) + (p2.y - p1.y) * Math.cos(deg) + p1.y;
    	Point rotated_p2 = new Point();
    	//System.out.printf("rotated_line: %f, %f", x_rotated, y_rotated);
    	rotated_p2.set_point(x_rotated, y_rotated);

    	return rotated_p2;
    }
    private static Point[] two_arr2one(Point[] arr1, Point[] arr2){
    	Point[] one = new Point[arr1.length + arr2.length];
    	System.arraycopy(arr1, 0, one, 0, arr1.length);
    	System.arraycopy(arr2, 0, one, arr1.length, arr2.length);
    	return one;
    }
    
	public static void print_points(Point[] arr){
		for(Point element: arr){
			System.out.printf("%f %f\n", element.x, element.y);
		}
	}
}

class Point{
	double x;
	double y;
	void set_point(double p_x, double p_y){
		x = p_x;
		y = p_y;
	} 
}
