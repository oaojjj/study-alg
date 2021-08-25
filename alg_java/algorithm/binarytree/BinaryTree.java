package algorithm.binarytree;

public class BinaryTree {
    Node root = null;
    int size = 0;

    private static class Node {
        String item;
        Node left;
        Node right;

        public Node(String item) {
            this.item = item;
            left = null;
            right = null;
        }

        public boolean hasChildNode() {
            return this.left != null || this.right != null;
        }
    }


    public void add(String item) {
        Node newNode = new Node(item);

        // 1. is the empty tree?
        if (isEmpty()) root = newNode;
        else {
            // 2. not empty -> add node
            Node temp = root;

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

    public Node delete(String item) {
        return null;
    }

    public boolean contain(String item) {

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
