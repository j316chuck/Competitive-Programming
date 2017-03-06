public interface list61b<T> { //T is type
	public void insertFront(T x); //every single object inherits from this
	public T getFront();
	public void InsertBack(T x);
	public T getBack();
	public T deleteBack();
	public int size();
	public T get(int position);
	public void insert(T item, int position);
	
	//default = default function that every single lower class inherits
	default public void print(){
		for(int i = 0; i < size(); i++){
			System.out.print(get(i) + " ");
		}
		System.out.println();
	}	
}
