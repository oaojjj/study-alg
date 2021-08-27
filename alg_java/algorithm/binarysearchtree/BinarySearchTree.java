package algorithm.binarysearchtree;

import structure.Node;
import structure.nonlinear.BinaryTree;

public class BinarySearchTree<T extends Comparable<T>> extends BinaryTree<T> {

    public BinarySearchTree() {
    }

    public BinarySearchTree(T[] data) {
        super(data);
    }

    public BinarySearchTree(T data, BinaryTree<T> leftTree, BinaryTree<T> rightTree) {
        super(data, leftTree, rightTree);
    }

    // binaryTree에서 구현한 insert와 기능적으로 동일하나 다른 방식으로 구현해봄..
    public void insert(T data) {
        Node<T> newNode = new Node<>(data);
        if (isEmpty()) root = newNode;

        Node<T> temp = root, prev;
        do {
            prev = temp;
            if (temp.data.compareTo(newNode.data) >= 0) temp = temp.left;
            else temp = temp.right;
        } while (temp != null);

        if (prev.data.compareTo(newNode.data) >= 0) prev.left = newNode;
        else prev.right = newNode;
    }

    public boolean search(T data) {
        Node<T> temp = root;
        while (temp != null) {
            int result = temp.data.compareTo(data);

            if (result == 0) return true;
            temp = result > 0 ? temp.left : temp.right;
        }
        return false;
    }

    public Node<T> delete(String item) {
        // case 1: has no child
        // case 2: has one child
        // case 3: has two child
        return null;
    }


}
