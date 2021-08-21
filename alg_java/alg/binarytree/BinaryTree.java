package alg.binarytree;

public class BinaryTree<T> {
    Node<T> root = null;
    int size = 0;

    private static class Node<E> {
        E item;
        Node<E> left;
        Node<E> right;

        public Node(E item) {
            this.item = item;
            left = null;
            right = null;
        }

        public boolean hasChildNode() {
            return this.left != null || this.right != null;
        }
    }


    public void add(T item) {
        Node<T> newNode = new Node<>(item);

        // 1. is the empty tree?
        if (isEmpty()) root = newNode;
        else {
            // 2. not empty -> add node
            Node<T> temp = root;

            while (temp.hasChildNode()) {
                if (temp.item)
                    temp = temp.left;
                temp = temp.right;
            }
        }
        size++;
    }

    private boolean isEmpty() {
        return size == 0;
    }

    public Node<T> delete(T item) {
        return null;
    }

    public boolean contain(T item) {

        return false;
    }

    public void inorder() {

    }

    public void preorder() {

    }

    public void postorder() {

    }

    public void levelOrder() {

    }
}
