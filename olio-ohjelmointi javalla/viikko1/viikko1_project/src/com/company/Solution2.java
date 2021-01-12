package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class Solution2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna korkeus: ");
        int korkeus = input.nextInt();
        System.out.print("Anna leveys: ");
        int leveys = input.nextInt();
        input.nextLine();
        System.out.print("Anna piirtomerkki: ");
        String merkki = input.nextLine();
        System.out.print("Täytetty vai ei (k=kyllä, e=ei):");
        String taytetty = input.nextLine();
        if(taytetty.equals("k")) {
            for (int i = 0; i < korkeus; i++) {
                for (int j = 0; j < leveys-1; j++) {
                    System.out.print(merkki);
                }
                System.out.println(merkki);

            }
        }else if (taytetty.equals("e")){
            for (int i = 0; i < korkeus; i++) {
                for (int j = 0; j < leveys-1; j++) {
                    if(i==0 || j==0 || i==korkeus-1) {
                        System.out.print(merkki);
                    }
                    else
                        System.out.print(" ");
                }
                System.out.println(merkki);
            }
        }else{
            System.out.println("Ei kelvollinen syöte.");;
        }


    }
}
