package com.company;

import java.util.Scanner;

public class Solution3 {
    public static void main(String[] args) {
        double tulo, summa, suurin;
        tulo=summa=suurin=0;
        int kuukausi = 0;
        Scanner input = new Scanner(System.in);
        while(tulo>=0){
            System.out.print("Anna " + (kuukausi+1) + ". kuukauden tulo: ");
            tulo=input.nextDouble();
            if (tulo>=0) {
                kuukausi++;
                summa += tulo;
                if (tulo > suurin) {
                    suurin = tulo;
                }
            }
        }
        System.out.println("Kokonaistulot ovat "+ summa);
        System.out.printf("Keskiarvoinen kuukausikohtainen tulo on %.1f\n", summa/kuukausi);
        System.out.println("Suurin kuukausikohtainen tulo on " + suurin);
    }
}
