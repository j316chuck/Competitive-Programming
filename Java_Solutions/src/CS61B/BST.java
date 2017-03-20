package CS61B;
import java.util.*;
import java.util.Iterator;
import java.util.Set;

public class BST{
    public int label;
    public BST left, right;

    public BST(int label) {
        this(label, null, null);
    }

    public BST(int label, BST left, BST right) {
        this.label = label;
        this.left = left;
        this.right = right;
    }

    public BST find(int L) {
        //throw new UnsupportedOperationException();
        if (this == null || L == label) {
            return this;
        } else if (L < this.label) {
            return left.find(label);
        } else {
            return right.find(label);
        }
    }

    public BST remove() {
        throw new UnsupportedOperationException();
    }

    public BST insert(BST T, int L) {
        if (T == null) {
            return new BST (L, null, null);
        } else if (L < label) {
            T.left = insert(T.left, L);
        } else{
            T.right = insert(T.right, L);
        }
        return T;
    }

    public BST insert(int L) {
        return this.insert(this, L);
    }

}

