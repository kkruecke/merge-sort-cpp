/*
From: http://www.cs.utep.edu/ofuentes/cs2302/fall11/nonRecursiveMergesort.txt
*/
import java.util.*;

public class nonRecursiveMergesort{	

	public static void merge(int [] A, int first, int last){
	// Preconditions: A[first ... mid] and A[mid+1 ... last] are sorted
	// Postcondition: A[first ... last] is sorted 
		int [] temp = new int[last-first+1];
		if (first<last){
			int i1 = first;
			int mid = (first+last)/2;
			int i2 = mid+1;
						
			for(int i=0;i< temp.length;i++){
				if (i1>mid){
					temp[i]= A[i2];
					i2++;
				}				
				else 
					if (i2>last){
						temp[i]= A[i1];
						i1++;
					}
					else
						if (A[i1]<A[i2]){
							temp[i]= A[i1];
							i1++;
						}
						else{
							temp[i]= A[i2];
							i2++;
						}
			//	System.out.println(i+" "+temp[i]); //for debugging purposes
			}
			for(int i=0;i<temp.length;i++)
				A[first+i]=temp[i];
		}
	}

	public static void mergesort(int [] A){
		Stack<MergesortRecord> stack=new Stack();
		MergesortRecord m = new MergesortRecord(false, 0, A.length-1);
		stack.push(m);
		while (!stack.empty()){
			/* Debugging code */
			System.out.println("Stack size is: " + stack.size());
			System.out.print("Top of stack is: ");
			stack.peek().print();
					
			m=stack.pop();
			//m.print(); //for debugging purposes
			if (m.getsorted()){//If first and second halves of array have been sorted, merge them
				merge(A,m.getfirst(),m.getlast());
			}
			else{
				if (m.getfirst()<m.getlast()){
					int mid = (m.getfirst()+m.getlast())/2;
					stack.push(new MergesortRecord(true,m.getfirst(),m.getlast()));
					stack.push(new MergesortRecord(false,m.getfirst(),mid));
					stack.push(new MergesortRecord(false,mid+1,m.getlast()));
				}
			}
			System.out.print("Current array is: ");
			printArray(A); //for debugging purposes	
			System.out.println();
		}
	}
	
	public static int [] generateRandomArray(int n, int max){
		Random generator = new Random();
		int []randArray = new int[n];
		for(int i=0;i<n;i++)
			randArray[i] = generator.nextInt(max);
		return randArray;
	}
	
	public static void printArray(int [] A){
		for(int i =0;i<A.length;i++)
			System.out.print(A[i]+" ");
		System.out.println();
	}

	public static void main(String[] args)   {
		int [] A = {3, 4, 8, 2, 9, 7};
		//int [] A = generateRandomArray(50,100);
		//printArray(A);
		mergesort(A);
		//printArray(A);
			
	}
}

/***************************************************************************************
************ Defines Objects to be used by the non-recursive Mergesort routine *********
************ Programmed by Olac Fuentes                                        *********
************ Last modified September 12, 2011                                  ********* 
****************************************************************************************/

import java.util.*;

public class MergesortRecord{	
	private boolean sorted; //Indicates if the first and second half of the array have already been sorted 
	private int first;
	private int last;
	
	public MergesortRecord(boolean s, int f, int l){
		sorted = s;
		first = f;
		last = l;
	}

	public  int getfirst()   {
			return first;
	}
	
	public boolean getsorted()   {
			return sorted;
	}
	
	public  int getlast()   {
			return last;
	}
	
	public void print(){
		System.out.println(sorted+" "+first+" "+last);
	}
}
