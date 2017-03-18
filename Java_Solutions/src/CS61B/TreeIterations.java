package CS61B;

public class TreeIterations {
    private static void inOrder(BST tree) {
        if (tree == null) return;
        inOrder(tree.left);
        System.out.println(tree.label);
        inOrder(tree.right);
    }

    private static void postOrder(BST tree) {
        if (tree == null) return;
        postOrder(tree.left);
        postOrder(tree.right);
        System.out.println(tree.label);
    }

    private static void preOrder(BST tree) {
        if (tree == null) return;
        System.out.println(tree.label);
        preOrder(tree.left);
        preOrder(tree.right);
    }

    private static class FindNum implements Action {
        boolean found = false;
        int num;

        public FindNum(int num) {
            this.num = num;
        }

        @Override
        public void visit(BST T) {
            if (T.label == num) {
                found = true;
            }
        }
    }

    private static void preOrderFunction(BST tree, Action act) {
        if (tree == null) return;
        act.visit(tree);
        preOrderFunction(tree.left, act);
        preOrderFunction(tree.right, act);
    }

    public static void main(String[] args) {
        BST t = new BST(3);
        t.insert(2);
        t.insert(4);
        t.insert(1);
        t.insert(5);
        FindNum findnumber = new FindNum(5);
        preOrderFunction(t, findnumber);
        System.out.println(findnumber.found);
        preOrder(t); //3 2 1 4 5
        inOrder(t); //1 2 3 4 5
        postOrder(t); //1 2 5 4 3
    }
}
interface Action {
    void visit(BST T);
}
