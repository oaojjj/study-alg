package structure.nonlinear;

import structure.Node;

import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree<T extends Comparable<T>> {
    public Node<T> root;
    int level;

    public BinaryTree() {
        root = null;
    }

    private BinaryTree(Node<T> root) {
        this.root = root;
    }

    public BinaryTree(T[] dataList) {
        for (T data : dataList) insert(data);
    }

    public BinaryTree(T data, BinaryTree<T> leftTree, BinaryTree<T> rightTree) {
        root = new Node<>(data);

        root.left = leftTree != null ? leftTree.root : null;
        root.right = rightTree != null ? rightTree.root : null;
    }

    public void insert(T data) {
        if (root == null) root = new Node<>(data);
        else if (root.data.compareTo(data) >= 0) {
            if (root.left != null) getLeftSubtree().insert(data);
            else root.left = new Node<>(data);
        } else {
            if (root.right != null) getRightSubtree().insert(data);
            else root.right = new Node<>(data);
        }
    }

    public BinaryTree<T> getLeftSubtree() {
        if (root != null && root.left != null)
            return new BinaryTree<>(root.left);
        return null;
    }

    public BinaryTree<T> getRightSubtree() {
        if (root != null && root.right != null)
            return new BinaryTree<>(root.right);
        return null;
    }

    public void traverseInorder() {

    }

    public void traversePreorder() {

    }

    public void traversePostorder() {

    }

    // using queue
    public void traverseLevelOrder() {
        if (root == null) return;

        Queue<Node<T>> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            Node<T> node = queue.poll();
            System.out.print(node.data + " ");

            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
        }
    }

    // using recursion
    public void traverseLevelOrder(Node<T> node, int level) {

    }
}
