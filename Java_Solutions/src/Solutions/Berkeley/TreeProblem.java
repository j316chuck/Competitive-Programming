package Solutions.Berkeley;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class TreeProblem {

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in")); //probably need to comment this
        Scanner in = new Scanner(System.in); // probably need to uncomment this

        int caseNumber = 1;
        while (in.hasNext()) {
            System.out.print("Case " + caseNumber + ": ");
            String preOrder = in.next();
            String inOrder = in.next();
            solve(preOrder, inOrder);
            caseNumber += 1;

            System.out.println(); //add two extra lines too align with formatting specifics
            System.out.println();
        }
        in.close();
        System.exit(0);
    }

    //this solution solves the problem in O(n^2logn) time, if you need to make it faster cause it doesn't pass the test cases
    //let me know and I can optimize it for you to O(nlogn) time
    //I can explain the reason why this code works later but try to understand my poorly documented code for now.
    //this problem was neat. the solution generally goes along the line of divide and conquer as you recursively solve the problem
    //for its left and right subtrees.
    private static void solve(String preOrder, String inOrder) {
        if (preOrder.isEmpty()) { //base case when you have an empty tree
            return;
        }
        char root = preOrder.charAt(0);
        String leftInOrder = "", rightInOrder = "", leftPreOrder = "", rightPreOrder = "";
        if (preOrder.length() == 1) { //base case when you have only one letter in the tree
            System.out.print(root);
            return;
        }

        //generating leftInOrder and rightInOrder subtree
        for (int i = 0; i < inOrder.length(); i++) {
            if (inOrder.charAt(i) == root) {
                leftInOrder = inOrder.substring(0, i);
                rightInOrder = inOrder.substring(i + 1);
                break;
            }
        }

        //generating leftPreOrder and rightPreOrder subtrees;
        for (int i = 1; i < preOrder.length(); i++) {
            if (!(leftInOrder.length() == 0) && leftInOrder.indexOf(preOrder.charAt(i)) != -1) {
                leftPreOrder += preOrder.charAt(i);
            } else {
                rightPreOrder += preOrder.charAt(i);
            }
        }

        //postorder is left tree, right tree, root so -> solve left tree, solve right tree, print root character;
        solve(leftPreOrder, leftInOrder); // solve left tree
        solve(rightPreOrder, rightInOrder); //solve right tree
        System.out.print(root);
    }
}

