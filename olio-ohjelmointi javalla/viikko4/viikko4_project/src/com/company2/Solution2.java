package com.company2;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution2 {
    public static void main(String[] args) {
        ArrayList<Henkilo> henkilot =new ArrayList<Henkilo>();
        Scanner input=new Scanner(System.in);
        String vastaus;
        while(true) {
            System.out.print("Lisätäänkö uusi henkilö? (k/e): ");
            vastaus=input.nextLine();
            if(vastaus.equals("k")) {
                System.out.print("Onko henkilo opiskelija vai henkilökuntaa? (o/h)");
                vastaus=input.nextLine();
                if(vastaus.equals("o")) {
                    final Opiskelija op = new Opiskelija();
                    op.kysyTiedot();
                    henkilot.add(op);
                }
                else if(vastaus.equals("h")){
                    final Henkilokunta henkunt = new Henkilokunta();
                    henkunt.kysyTiedot();
                    henkilot.add(henkunt);
                }
                else{
                    System.out.println("Et antanut kelpoa vastausta. Yritä uudelleen");
                }
            }
            else if (vastaus.equals("e")) {
                break;
            }
            else {
                System.out.println("Et antanut kelpoa vastausta. Yritä uudelleen");
            }
        }

        for (Henkilo o : henkilot){
            if(o instanceof Opiskelija){
                final Opiskelija op = (Opiskelija) o;
                System.out.println(op.tulostaOpiskelija()); // tehtävänanto ei määritellyt tulostuksen muotoa ja tapaa
            }
        }
        for (Henkilo h : henkilot){
            if(h instanceof Henkilokunta){
                final Henkilokunta henkunt = (Henkilokunta) h;
                System.out.println((((Henkilokunta) h).tulostaHenkilokunta())); // tehtävänanto ei määritellyt tulostuksen muotoa ja tapaa
            }
        }


        // System.out.println("Luodan opiskelija...");
        // Opiskelija mallioppilas = new Opiskelija("Matti", "Osoite 1234", "4.9.94", 13144, "1.6.2020");
        // System.out.println("tulostaOpiskelija: " +  mallioppilas.tulostaOpiskelija());
         // System.out.println("Luodan henkilokunta...");
        // Henkilokunta mallihenkilokunta = new Henkilokunta("Liisa", "Osoite 123", "4.9.90", "ABC123", "Helsinki", "Yliopettaja");
        // System.out.println("tulostaHenkilokunta: " +  mallihenkilokunta.tulostaHenkilokunta());
    }
}
