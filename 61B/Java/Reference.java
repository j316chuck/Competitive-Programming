public class Reference{
	public static void main(String[] args){

	}

	public class IntList{
		public int first;
		public IntList rest;

		public IntList(int f, Intlist r){
			first = f;
			rest = r;
		}

		public int size(){
			if(rest == null){ //this == null does not work!!!
				return 1;
			}
			return 1 + this.rest.size();
		}

		public int iterativeSize(){
			IntList p = this //pointer/reference to the variable;
			int total = 0;
			while(p != null){
				total+=1;
				p = p.rest;
			}
			return total;
		}

		public int get(int i){
			if(i == 0){
				return first;
			}
			return this.rest(i-1);
		}
	}
}

/* this is a reference to the variable or class that the java is handling*/
//use this typically and catch nulls early
//this.methodone()
/*
Notes: Java Objects have pass by reference aka
Walrus a =  new Walrus(1000, 8.3);
Walrus b = a; //changing it by passing the reference
b is now pointing to the same reference as a.
(a change in b will create a change in a)
Does not have null default value. Will be given a default value like 0 or null


Note: Java Primitive types
Boolean char int etc.
a change in int will not carry over
int a = 3;
int b = 4;
a = b; //copying bits over
b = 5; //copying bits over
a is still 4;
Note: Null default values. cannot call if null
there is null in java.
*/

/*
computer stores all the millions of bits
declaration creates a box of empty bits between a random memory space you cannot see
then when you initialize/assign the variable it calculates the storage and the data of the variable
yay that's pretty cool
*/


/*
new operator returns address of the operator. 
declare variable of any type of reference = stores 64 bits of data always
then new operator returns address of new Walrus created...
this address is copied to someWalrus box. Then we can access all the two variables. 
if walrus has a double and an int then it is 96 bits.
null = reference all 0's 
*/

/*
GROE 
copy bits of b into bits of a 
If b is reference then you would be copying address
If b is value then you would be copying value
*/


/*
In java you always pass by value.
Always copy the bits.
Even in functions. That means the walrus's change inside functions
*/

x = new int[]{0, 1, 2, 95, 4};
//creates a new array of size 5. x contains the address...