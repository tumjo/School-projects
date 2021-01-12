package com.company2;

import java.util.Scanner;

public class Henkilo {
    private String nimi;
    private String osoite;
    private String syntymaaika;

    public Henkilo(){

    }

    public Henkilo(String nimi, String osoite, String syntymaaika) {
        this.nimi=nimi;
        this.osoite=osoite;
        this.syntymaaika=syntymaaika;
    }

    // metodi luokan perillisille
    protected String getHenkilonTiedot() {
        return nimi + ", " + osoite + ", " + syntymaaika;
    }

    public void kysyTiedot() {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna nimi: ");
        nimi=input.nextLine();
        System.out.print("Anna osoite: ");
        osoite=input.nextLine();
        System.out.print("Anna syntyma-aika: ");
        syntymaaika=input.nextLine();
    }
}
