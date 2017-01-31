public static testing{
	public static int indexofsmallest(String[] inputs, int k){
		int mindex = k;
		for(int i = k; i < inputs.length; i++){
			int cmp = inputs[i].compareTo(inputs[minDex]);
			if(cmp < 0){
				mindex = 1;
			}
		}
		return mindex;
		
	}
	public static void testindex(){
		String[] input = {"glorious", "pigs", "dream", "again"};
		int expected = 3;
		int actual = Sort.indexofSmallest(input, 0);
		org.junit.Assert.assertEquals(expected, actual);
		//org.junit.Assert.assertEquals(expected, actual);
		//testing = write test functions
		//testindex = write expected, actual
		//org.junit.Assert.assertEquals(expected, actual)
		//import org.junit.Test;
		//import static org.junit.Assert.*;
	}
}
