package com.company2;

import java.util.Scanner;

public class Opiskelija extends Henkilo {
    private int opiskelijanumero;
    private String aloituspaiva;

    Opiskelija(){

    }

    Opiskelija(String nimi, String osoite, String syntymaaika, int opiskelijanumero, String aloituspaiva){
        super(nimi, osoite, syntymaaika);
        this.opiskelijanumero=opiskelijanumero;
        this.aloituspaiva=aloituspaiva;
    }

    String tulostaOpiskelija() {
        return super.getHenkilonTiedot() + ", " + opiskelijanumero + ", " + aloituspaiva;
    }

    @Override
    public void kysyTiedot() {
        super.kysyTiedot();
        Scanner input = new Scanner(System.in);
        System.out.print("Anna opiskelijanumero: ");
        opiskelijanumero=input.nextInt();
        input.nextLine();
        System.out.print("Anna aloituspaiva: ");
        aloituspaiva=input.nextLine();


    }
}

