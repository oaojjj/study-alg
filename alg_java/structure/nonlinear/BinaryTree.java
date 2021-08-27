package structure.nonlinear;

import structure.Node;

import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree<T extends Comparable<T>> {
    protected Node<T> root = null;

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

    protected void insert(Node<T> node, T data) {
        // 1. is the empty tree?
        if (node == null) root = new Node<>(data);
            // 2. if not empty -> find a space to add
        else if (node.data.compareTo(data) >= 0) {
            if (node.left != null) insert(node.left, data);
            else node.left = new Node<>(data);
        } else {
            if (node.right != null) insert(node.right, data);
            else node.right = new Node<>(data);
        }
    }

    protected boolean isEmpty() {
        return root == null;
    }

    public void traverseInorder(Node<T> node) {
        if (node == null) return;

        traverseInorder(node.left);
        System.out.print(node.data + " ");
        traverseInorder(node.right);
    }

    // 함수를 한번 더 거치지만 매개변수 없이 이렇게도 가능
    public void traverseInorder() {
        if (isEmpty()) return;

        System.out.print(root.data + " ");
        if (root.left != null) getLeftSubtree().traverseInorder();
        if (root.right != null) getRightSubtree().traverseInorder();
    }

    public void traversePreorder(Node<T> node) {
        if (node == null) return;

        System.out.print(node.data + " ");
        traversePreorder(node.left);
        traversePreorder(node.right);
    }

    public void traversePostorder(Node<T> node) {
        if (node == null) return;

        traversePostorder(node.left);
        traversePostorder(node.right);
        System.out.print(node.data + " ");
    }

    /**
     * @param version 1: using queue, 2: using recursion
     */
    public void traverseLevelOrder(int version) {
        if (version == 1) traverseLevelOrderQueue();
        else if (version == 2) {
            int h = getTreeHeight(root);
            for (int i = 1; i <= h; i++) traverseLevelOrderRecursion(root, i);
        }
    }

    // using queue
    protected void traverseLevelOrderQueue() {
        if (isEmpty()) return;

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
    protected void traverseLevelOrderRecursion(Node<T> node, int level) {
        if (node == null) return;
        if (level == 1) System.out.print(node.data + " ");
        else if (level > 1) {
            traverseLevelOrderRecursion(node.left, level - 1);
            traverseLevelOrderRecursion(node.right, level - 1);
        }
    }

    protected int getTreeHeight(Node<T> node) {
        if (node == null) return 0;
        return 1 + Math.max(getTreeHeight(node.left), getTreeHeight(node.right));
    }

    public Node<T> getRoot() {
        return root;
    }

    public BinaryTree<T> getLeftSubtree() {
        if (!isEmpty() && root.left != null)
            return new BinaryTree<>(root.left);
        return null;
    }

    public BinaryTree<T> getRightSubtree() {
        if (!isEmpty() && root.right != null)
            return new BinaryTree<>(root.right);
        return null;
    }
}
