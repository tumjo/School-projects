package com.company3;

import java.util.Scanner;
// Toinen toteutusversio ja muutamia parempia käytänteitä
public class Solution2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        OmatJaYhteisetTilit tilitiedot= new OmatJaYhteisetTilit();

        System.out.print("Anna oman tilin numero: ");
        tilitiedot.omaTili.setTilinumero(input.nextLine());
        System.out.print("Anna yhteisen tilin numero: ");
        tilitiedot.yhteinenTili.setTilinumero(input.nextLine());
        System.out.print("Anna oman tilin omistaja: ");
        tilitiedot.omaTili.setOmistaja(input.nextLine());
        System.out.print("Anna yhteisen tilin omistaja: ");
        tilitiedot.yhteinenTili.setOmistaja(input.nextLine());
        System.out.print("Anna oman tilin saldo(€): ");
        tilitiedot.omaTili.setSaldoEuroa(input.nextDouble());
        System.out.print("Anna yhteisen tilin saldo(€): ");
        tilitiedot.yhteinenTili.setSaldoEuroa(input.nextDouble());
        boolean isTrue=false;
       do
            try {
                System.out.print("Anna oman tilin vuosikorko(%): ");
                tilitiedot.omaTili.setVuosikorko(input.nextDouble());
                isTrue=true;
            }catch (ArithmeticException e){
                System.out.println(e);
                System.out.println("Yritä uudelleen!");
            }while(!isTrue);
        isTrue=false;
        do
            try {
                System.out.print("Anna yhteisen tilin vuosikorko(%): ");
                tilitiedot.yhteinenTili.setVuosikorko(input.nextDouble());
                isTrue=true;
            }catch (ArithmeticException e){
                System.out.println(e);
                System.out.println("Yritä uudelleen!");
            }while(!isTrue);
        tilitiedot.omaTili.tulostaTilinTiedot();
        tilitiedot.yhteinenTili.tulostaTilinTiedot();
    }
}
