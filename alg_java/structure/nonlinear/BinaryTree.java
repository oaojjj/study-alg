package structure.nonlinear;

import structure.Node;

import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree<T extends Comparable<T>> {
    public Node<T> root = null;

    public BinaryTree() {
    }

    private BinaryTree(Node<T> node) {
        this.root = node;
    }

    public BinaryTree(T[] dataList) {
        for (T data : dataList) insert(root, data);
    }

    public BinaryTree(T data, BinaryTree<T> leftTree, BinaryTree<T> rightTree) {
        root = new Node<>(data);

        root.left = leftTree != null ? leftTree.root : null;
        root.right = rightTree != null ? rightTree.root : null;
    }

    public void insert(Node<T> node, T data) {
        if (node == null) root = new Node<>(data);
        else if (node.data.compareTo(data) >= 0) {
            if (node.left != null) getLeftSubtree().insert(node.left, data);
            else node.left = new Node<>(data);
        } else {
            if (node.right != null) getRightSubtree().insert(node.right, data);
            else node.right = new Node<>(data);
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

    /**
     * @param version 1: using queue, 2: using recursion
     */
    public void traverseLevelOrder(int version) {
        if (version == 1) traverseLevelOrderQueue();
        else if (version == 2) {
            int h = treeHeight(root);
            for (int i = 1; i <= h; i++) traverseLevelOrderRecursion(root, i);
        }
    }

    // using queue
    public void traverseLevelOrderQueue() {
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
    public void traverseLevelOrderRecursion(Node<T> node, int level) {
        if (node == null) return;
        if (level == 1) System.out.print(node.data + " ");
        else if (level > 1) {
            traverseLevelOrderRecursion(node.left, level - 1);
            traverseLevelOrderRecursion(node.right, level - 1);
        }
    }

    public int treeHeight(Node<T> node) {
        if (node == null) return 0;
        return 1 + Math.max(treeHeight(node.left), treeHeight(node.right));
    }

}
