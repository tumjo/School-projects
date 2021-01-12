package com.company2;

import java.util.Scanner;

public class Solution2 {
    public static void main(String[] args) {
        //Tehtävänanto ei määritellyt tarkemmin kuinka toteutus, mutta tehdään niin että kysytään tiedot saastotili ja supersaastotili olioihin. Asetetaan tämän jälkeen tiedot koosteluokkaan tekemällä olioista syväkopiot kopioalustajilla.

        Scanner input = new Scanner(System.in);
        Saastotili oma =new Saastotili();
        SuperSaastoTili yhteinen=new SuperSaastoTili();
        double vuosik;

        System.out.print("Anna oman tilin numero: ");
        oma.setTilinumero(input.nextLine());
        System.out.print("Anna yhteisen tilin numero: ");
        yhteinen.setTilinumero(input.nextLine());
        System.out.print("Anna oman tilin omistaja: ");
        oma.setOmistaja(input.nextLine());
        System.out.print("Anna yhteisen tilin omistaja: ");
        yhteinen.setOmistaja(input.nextLine());
        System.out.print("Anna oman tilin saldo(€): ");
        oma.setSaldoEuroa(input.nextDouble());
        System.out.print("Anna yhteisen tilin saldo(€): ");
        yhteinen.setSaldoEuroa(input.nextDouble());
       do
            try {
                System.out.print("Anna oman tilin vuosikorko(%): ");
                oma.setVuosikorko(input.nextDouble());
                break;
            }catch (ArithmeticException e){
                System.out.println(e);
                System.out.println("Yritä uudelleen!");
            }while(true);

        do
            try {
                System.out.print("Anna yhteisen tilin vuosikorko(%): ");
                yhteinen.setVuosikorko(input.nextDouble());
                break;
            }catch (ArithmeticException e){
                System.out.println(e);
                System.out.println("Yritä uudelleen!");
            }while(true);



        OmatJaYhteisetTilit tilitiedot = new OmatJaYhteisetTilit(oma, yhteinen);
        System.out.println(tilitiedot.toString());
        tilitiedot.tulostaTilienTiedot();
    }
}
