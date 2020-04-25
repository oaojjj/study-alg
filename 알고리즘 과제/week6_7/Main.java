package week6_7;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main {
	static final String PATHS = "C:\\Users\\Oseong\\workspace\\Assignment\\src\\week6_7\\";
	// String testFileName = "address_book2020.csv";
	static String fieldName;
	static BinarySearchTree bst = new BinarySearchTree();

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String command;
		String name;
		String fileName;

		while (true) {
			System.out.print("$ ");
			command = in.next();
			if (command.equals("exit"))
				break;
			else if (command.equals("read")) {
				fileName = in.next();
				readCsv(PATHS + fileName);
			} else if (command.equals("list")) {
				bst.list(bst.getRoot());
			} else if (command.equals("find")) {
				name = in.next();
				bst.printInfo(bst.find(name));
			} else if (command.equals("trace")) {
				name = in.next();
				bst.trace(name);
			} else if (command.equals("delete")) {
				name = in.next();
				bst.delete(name);
			} else if (command.equals("save")) {
				fileName = in.next();
				saveCsv(PATHS + fileName);
			}

		}

		in.close();
	}

	public static void readCsv(String paths) {

		try {
			BufferedReader br = Files.newBufferedReader(Paths.get(paths));

			fieldName = br.readLine();
			String line = "";

			while ((line = br.readLine()) != null) {
				// 정규표현식을 이용해서 문자열 분리
				String data[] = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

				// 쌍따옴표 제거
				if (data[1].charAt(0) == '\"') {
					data[1] = data[1].substring(1, data[1].length() - 1);
				}
				if (data[2].charAt(0) == '\"') {
					data[2] = data[2].substring(1, data[2].length() - 1);
				}

				// 노드 추가
				bst.insert(new BinarySearchTree.Node(new Person(data[0], data[1], data[2], data[3], data[4], data[5])));
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public static void saveCsv(String paths) {
		try {
			BufferedWriter bw = Files.newBufferedWriter(Paths.get(paths), Charset.forName("UTF-8"));
			List<Person> lp = new ArrayList<Person>();
			StringBuilder sb = new StringBuilder();
			// 클래스 안에 만들어도 될듯
			dataToString(bst.getRoot(), lp);
			// 필드네임부터 추가
			bw.write(fieldName);
			bw.newLine();
			for (int i = 0; i < lp.size(); i++) {
				Person p = lp.get(i);
				// 다시 쌍따옴표 붙이기...
				if (p.getCompany().contains(", ")) {
					p.setCompany('\"' + p.getCompany() + '\"');
				}
				if (p.getAddress().contains(", ")) {
					p.setAddress('\"' + p.getAddress() + '\"');
				}

				// 하나의 문자열로 만들기
				sb.append(p.getName() + ',').append(p.getCompany() + ',').append(p.getAddress() + ',')
						.append(p.getZipcode() + ',').append(p.getPones() + ',').append(p.getEmail() + ',');

				bw.write(sb.toString());
				bw.newLine();
				sb.delete(0, sb.length());
			}
			bw.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// 노드에 들어있는 데이터 불러오기
	public static void dataToString(BinarySearchTree.Node node, List<Person> lp) {
		if (node == null)
			return;
		else {
			dataToString(node.getLeft(), lp);
			lp.add(node.getData());
			dataToString(node.getRight(), lp);
		}
	}
}
