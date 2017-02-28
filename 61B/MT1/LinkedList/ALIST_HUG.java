//items = (Glorp []) new Object[8];
//private Glorp items = (Glorp []) new Object[8]

public class AList<Item> {
	/* the stored integers */
	private Item[] items;
	private int size;

	private static int RFACTOR = 2;

    /** Creates an empty list. */
    public AList() {
    	size = 0;
    	items = (Item[]) new Object[100];
    }

    /** Resize our backing array so that it is
      * of the given capacity. */
    private void resize(int capacity) {
    	Item[] a = (Item[]) new Object[capacity];
    	System.arraycopy(items, 0, a, 0, size);
    	items = a;    	
    }

    /** Inserts X into the back of the list. */
    public void insertBack(Item x) {    	
    	if (size == items.length) {
    		resize(size * RFACTOR);
    	}

    	items[size] = x;
    	size = size + 1;
    }

    /** Returns the item from the back of the list. */
    public Item getBack() {
    	int lastActualItemIndex = size - 1;
    	return items[lastActualItemIndex];
    }
    /** Gets the ith item in the list (0 is the front). */
    public Item get(int i) {
        return items[i];
    }

    /** Returns the number of items in the list. */
    public int size() {
        return size;        
    }

    /** Deletes item from back of the list and
      * returns deleted item. */
    public Item deleteBack() {
		Item itemToReturn = getBack();
		/* setting to zero not strictly necessary, but
		 * it's a good habit (we'll see why soon) */
		items[size - 1] = null;
		size = size - 1;
		return itemToReturn;
    }

} 
