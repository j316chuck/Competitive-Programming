public class SLList{
	public static class intNode{
		public int item;
		public IntNode next;

		public IntNode(int i, IntNode n){
			item = i;
			next = n;
		}
	}

	private IntNode sentinel;
	private int size;

	public SLList(int x){
		sentinel = new IntNode(x, null);
		size = 1;
	}

	public SLList(){
		sentinel = new Intnode(3, null);
		size = 0;
	}
	public void addFirst(int x){
		sentinel = new Intnode(x, first);
		size += 1;
	}
	public void getFirst(){
		return sentinel.item;
	}

	public void addLast(int x){
		size+=1;
		/*if(p == null){
			p = new Int(x, p); 
			return;
		}*/
		IntNode p - sentinel;
		while(p.next != null){
			p = p.next;
		}
		p.next = new IntNode(x, null);
	}

	public int size(){
		return size;
	}
	/*public static int size(IntNode p){
		if(p.rest == null){
			return 1;
		}
		return 1 + size(p.next);
	}
	public int size(){
		return size(first);
	} //this.rest.size();*/
}

/*
Can add nested classes.
Private means everything outside the class cannot access
Also, you have to make sure the static variable means basically you don't need any instance members of the outer class
static can be referenced as class variable
overloaded methods allowed.
*/