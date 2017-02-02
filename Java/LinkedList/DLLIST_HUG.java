public class DLList<BleepBlorp> {
    private IntNode sentinel;
    private int size;

    public class IntNode {
        public IntNode prev;
        public BleepBlorp item;
        public IntNode next;
        ...
    }
    ...
}

Integer, Double, Character, Boolean, Long, Short, Byte, or Float, String

DLList<Integer> d1 = new DLList<Integer>(5);

