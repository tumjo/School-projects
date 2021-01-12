package com.company;

import java.util.Scanner;

public class Solution1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna osake: ");
        String osake = input.nextLine();
        System.out.print("Anna osinkopros: ");
        double osinkopros = input.nextDouble();
        System.out.print("Anna sijoitus: ");
        int sijoitus = input.nextInt();
        System.out.printf("Osakkeen " + osake + " tuotto pääomalle " + sijoitus + " on %.2f", osinkopros/100*sijoitus);
    }
}
