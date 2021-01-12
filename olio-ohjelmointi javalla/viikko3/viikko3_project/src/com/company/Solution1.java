package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution1 {

    public static void main(String[] args) {
        ArrayList<Osake> osakkeet = new ArrayList<Osake>();
        Scanner input = new Scanner(System.in);

        String vastaus;
        int a;
        int b;
        a=b=4;
        while(true) {
            System.out.print("Lisätäänkö uusi osake (k/e): ");
            vastaus=input.nextLine();
            if(vastaus.equals("k")) {
                Osake osa = new Osake();
                osa.kysyTiedot();
                osakkeet.add(osa);
            }
            else if (vastaus.equals("e")) {
                System.out.print("Anna kasvuprosentti vuodessa: ");
                Osake.setKasvuprosentti(input.nextDouble());
                System.out.print("Anna ajanjakso vuosina: ");
                Osake.setAjanjaksoVuosina(input.nextInt());
                break;
            }
            else {
                System.out.println("Et antanut kelpoa vastausta. Yritä uudelleen");
            }
        }
        for (Osake os : osakkeet) {
            os.tulostaArvo();
        }
        System.out.println();
        System.out.printf("Koko osakesalkun tuotto on annetulla ajanjaksolla ja korolla yhteensä %.2f", Osake.getOsakesalkunTuotto());
        System.out.print(" euroa.");

    }
}
