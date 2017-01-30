public class arrays{
	public static void main(String[] args){
		int[][] pascalsTriangle; //does nothing
		pascalTriangle = new int[4][]; //creates null null null null
		int[] rowZero = pascalsTriangle[0]; //because null htis makes rowZero = null not a pointer/reference to the array that is null

		pascalsTriangle[0] = new int[]{1}; //assigns the null array to a new array
		pascalsTriangle[1] = new int[]{1, 1}; //assigns the null array to a new array;
		pascalsTriangle[2] = new int[]{1, 2, 1};
		pascalsTrinagle[3] = new int[]{1, 3, 3, 1};
		int[] rowTwo = pascalsTriangle[2]; //pascalsTriangle = 2... array of two reference at this point;
		rowTwo[1] = -5 //changes both pascal triangle;

		int[][] pascalAgain = new int[][]{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}};

		//System.arraycopy(srcarray, srcstart, dstarray, dststart, length);
		int temp[] = new int[3];
		System.arraycopy(pascalAgain[0], 0, temp, )
	}
}