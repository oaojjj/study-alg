package week2;

import java.util.Scanner;

public class Prob1 {
	static Scanner sc = new Scanner(System.in);
	static int K;
	static int getRankSize(int n){
		if(n==0){
			K = sc.nextInt();
			return 0;
		}
		else{
			int number = sc.nextInt();
			int rank = getRankSize(n-1);
			if(number<K)
				return ++rank;
			else
				return rank;
		}
	}
}
