package com.exam3;

import java.util.ArrayList;
import java.util.Scanner;

public class t3 {
    public static void main(String[] args) {
        ArrayList<Pelaaja> pelaajat=new ArrayList<>(); // pelaajat
        ArrayList<Pelaaja> tietorakenne =new ArrayList<>(); // tietyn joukkueen pelaajat
        Scanner input=new Scanner(System.in);
        String vastaus;

        while(true){
            System.out.print("Anna pelaajan pelinumero (0 = Lopettaa syötön): ");
            vastaus=input.nextLine();
            if(vastaus.equals("0")){
                break;
            }
            Pelaaja pelaaja =new Pelaaja();
            pelaaja.kysyTiedot(vastaus);
            pelaajat.add(pelaaja);
        }

        System.out.print("Anna joukkue, jonka pelaajat haluat tallentaa tietorakenteeseen: ");
        vastaus=input.nextLine();
        tietorakenne=LiigaUtils.palautaPelaajat(vastaus, pelaajat);
        System.out.println("Tulostetaan tarkistuksen vuoksi tietorakenne...");
        // Vain tarkistusta verten for loop että kyseiset tiedot ovat todella tietorakenteessa.
        for(Pelaaja x : tietorakenne){
            System.out.println(x.getPelinumero() + x.getNimi() +  x.getJoukkue() + x.getPelipaikka() + x.getMaalit() + x.getSyotot());
        }

        System.out.println();
        System.out.println("Kauden maalit yhteensä: " + LiigaUtils.maalit(pelaajat));
    }
}
