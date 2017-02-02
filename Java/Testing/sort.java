public class sort{

	public static int indexOfSmallest(String[] inputs, int k){
		int minDex = k;
		for(int i = k; i < inputs.length; i++){
			int cmp = inputs[i].compareTo(inputs[minDex]);
			if(cmp < 0){
				minDex = i;
			}//cmp is less than 0 means inputs[mindex] is less
		}
		return minDex;
	}

	private	static String[] sort(String[] inputs, int k){
		if(k == inputs.length){
			return inputs;
		}
		int minDex = indexOfSmallest(inputs, k);
		swap(inputs, k , minDex);

		return sort(inputs, k+1);
	}

	private static void swap(String[] input, int a, int b){
		String temp = input[a];
		input[a] = input[b];
		input[b] = temp;
	}

	static void print(String[] a){
		for(String s: a){
			System.out.println(s);
		}
	}

	public static void main(String[] args){
		String[] s = sort(args, 0);
		print(s);		
	}
}

