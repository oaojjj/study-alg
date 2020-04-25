package week6_7;

public class BinarySearchTree {
	private Node root;

	public BinarySearchTree() {
		root = null;
	}

	public static class Node {
		private Person data;
		private Node parents; // delete를 쉽게 구현하기위해 추가
		private Node left;
		private Node right;

		public Node(Person item) {
			data = item;
			left = null;
			right = null;
			parents = null;
		}

		public Node getLeft() {
			return left;
		}

		public void setLeft(Node left) {
			this.left = left;
		}

		public Node getRight() {
			return right;
		}

		public void setRight(Node right) {
			this.right = right;
		}

		public Person getData() {
			return data;
		}

		public void setData(Person data) {
			this.data = data;
		}

	}

	public void insert(Node newNode) {
		String newName = newNode.data.getName();
		String name = null;

		// 따라 가는 친구
		Node pNode = null;
		// 탐색 하는 친구
		Node node = root;

		while (node != null) {
			pNode = node;
			name = node.data.getName();
			// 추가하려는 노드가 현재 노드보다 작다면 왼쪽노드로 감
			if (name.compareTo(newName) >= 0)
				node = node.left;
			// 크다면 오른쪽 노드
			else
				node = node.right;

		}
		// 루트노드가 없다면 만들어 줌
		if (pNode == null) {
			root = newNode;
		} else {
			newNode.parents = pNode;
			name = pNode.data.getName();
			// 현재 노드보다 작다면 왼쪽 노드에 추가
			if (name.compareTo(newName) >= 0)
				pNode.left = newNode;
			else
				pNode.right = newNode;
		}

	}

	public void list(Node node) {
		if (node == null)
			return;
		else {
			list(node.left);
			printInfo(node);
			list(node.right);
		}
	}

	public void printInfo(Node n) {
		if (n == null) {
			System.out.println("검색 결과가 없습니다.");
		} else {
			Person p = n.data;
			System.out.println(p.getName());
			System.out.println("  Company: " + p.getCompany());
			System.out.println("  Address: " + p.getAddress());
			System.out.println("  ZipCode: " + p.getZipcode());
			System.out.println("  Phones: " + p.getPones());
			System.out.println("  Email: " + p.getEmail());
		}
	}

	public Node find(String name) {
		Node node = root;

		while (node != null) {
			String newName = node.data.getName();
			// 내가 찾는 노드보다 작다면 왼쪽 노드로 감
			if (newName.compareTo(name) > 0)
				node = node.left;
			// 크다면 오른쪽 노드
			else if (newName.compareTo(name) < 0)
				node = node.right;
			else {
				return node;
			}
		}
		return node;
	}

	private boolean search(String name) {
		Node node = root;

		while (node != null) {
			String newName = node.data.getName();
			// 내가 찾는 노드보다 작다면 왼쪽 노드로 감
			if (newName.compareTo(name) > 0)
				node = node.left;
			// 크다면 오른쪽 노드
			else if (newName.compareTo(name) < 0)
				node = node.right;
			else
				return true;
		}
		return false;
	}

	public void trace(String name) {
		if (search(name)) {
			Node node = root;

			while (node != null) {
				String newName = node.data.getName();
				System.out.println(newName);
				// 내가 찾는 노드보다 작다면 왼쪽 노드로 감
				if (newName.compareTo(name) > 0)
					node = node.left;
				// 크다면 오른쪽 노드
				else if (newName.compareTo(name) < 0)
					node = node.right;
				else
					break;
			}
		} else
			System.out.println("검색 결과가 없습니다.");

	}

	public void delete(String name) {
		Node node = root;

		while (node != null) {
			String newName = node.data.getName();
			// 내가 찾는 노드보다 작다면 왼쪽 노드로 감
			if (newName.compareTo(name) > 0)
				node = node.left;
			// 크다면 오른쪽 노드
			else if (newName.compareTo(name) < 0)
				node = node.right;
			else
				break;
		}
		if (node == null)
			return;
		// case 1: 자식노드가 없는 경우
		// case 2: 중간에 삭제해야 될 경우
		// case 3: 루트노드일 경우

		Node y = null;
		Node x = null;
		// 삭제되는 노드 자식 0 or 1 일 때
		if (node.left == null || node.right == null)
			y = node;
		// 자식 2
		else
			y = getSuccessor(node);

		// 왼쪽 자식이 존재 -> 자식이 0 or 1
		if (y.left != null)
			x = y.left;
		else
			x = y.right;

		// x != null -> x의 부모는 y의 부모
		if (x != null)
			x.parents = y.parents;

		// 삭제할 노드가 root
		if (y.parents == null)
			root = x;
		// if y left
		else if (y == y.parents.left)
			y.parents.left = x;
		else
			y.parents.right = x;

		if (y != node)
			node.data = y.data;
	}

	public Node getMinNode(Node n) {
		Node node = n;
		while (node.left != null)
			node = node.left;
		return node;
	}

	public Node getMaxNode(Node n) {
		Node node = n;
		while (node.right != null)
			node = node.right;
		return node;
	}

	public Node getSuccessor(Node n) {
		Node node = n;
		if (node.right != null)
			return getMinNode(node.right);

		return node;

	}

	public Node getRoot() {
		return root;
	}

	public void setRoot(Node root) {
		this.root = root;
	}

}
