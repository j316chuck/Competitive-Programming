public class AList<Item>{
    private int size;
    private Item items;
    private int RFACTOR = 2;
    public AList(){
        items = (Item[]) new Object[101];
        size = 0;
    }
    //naive solution to resize
    public void addLast(Item x){
        if(size == items.length){
            resize(size*RFACTOR);
        }

        items[size] = x;
        size++;
    }

    public void resize(int capacity){
         Item a = (Item[]) new Object[capacity+1];   
         System.arraycopy(items, 0, a, 0, size);
         items = a;
    }

    public int getLast(){
        return A[size-1];
    }
    public int size(){
        return size;
    }
    public int get(int i){
        return items[i];
    }

    public int removeLast(){
        Item  x = getLast();
        items[size] = null;
        size = size-1;
        return x;
    }

   
    /*public static void main(String[] args){
        
     }*/
}
