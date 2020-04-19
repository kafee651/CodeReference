import java.util.*;

public class QuickSort {

    public static void swap(int a[], int i, int j){
	    int temp;

      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      return;
    }

    public static int partition_car_hoare(int a[], int p, int r){
  	  int i, j, x;
	
      x = a[p];
      i = p - 1;
      j = r + 1;
      while(true){
        while(x >= a[++i]);
        while(x <= a[--j]);
        if(i < j)
          swap(a, i, j);
        else{	
          swap(a, j, p);
          return(j);
        }
      }
     }

public static int partition_n_lomuto(int a[], int p, int r){
	int i, j, x;
	
	i = p - 1;
	x = r;
	for(j = p;j <= r;j++){
		if(a[x] >= a[j]){
			i++;
			swap(a, j, i);
		}
	}
	return(i);
}


  public static void quick_sort(int a[], int p, int r){
	int q, i;
	
	if(p < r){
		q = partition_n_lomuto(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
	
	return;
}
    public static void main(String[] args)  {
        Scanner in = new Scanner(System.in);
        int t = Integer.parseInt(in.nextLine()); 
        for (int i = 1; i <= t; ++i) {
            int n = Integer.parseInt(in.nextLine());
            int[] a = new int[n];
            for(int j = 0;j < n;j++){
              a[j] = in.nextInt();
            }
            quick_sort(a, 0, n-1);
            for(int j = 0;j < n;j++){
              System.out.println(a[j]);
            }
           
        }
        in.close();
    }
}



