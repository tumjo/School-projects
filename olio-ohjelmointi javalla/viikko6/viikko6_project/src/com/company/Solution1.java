package com.company;

import java.util.Scanner;

public class Solution1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int maara;
        System.out.print("Kuinka monta säiettä haluat: ");
        maara=Integer.parseInt(input.nextLine());
        PrintDiamond diamond=new PrintDiamond();
        for(int i=0; i<maara;i++){
            new Thread(diamond).start();
        }
    }
}
