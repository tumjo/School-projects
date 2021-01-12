package com.company;

public class Opiskelija extends Henkilo {
    private int opiskelijanumero;
    private String aloituspaiva;


    Opiskelija(String nimi, String osoite, String syntymaaika, int opiskelijanumero, String aloituspaiva){
        super(nimi, osoite, syntymaaika);
        this.opiskelijanumero=opiskelijanumero;
        this.aloituspaiva=aloituspaiva;
    }


    String tulostaOpiskelija() {
        return super.getHenkilonTiedot() + ", " + opiskelijanumero + ", " + aloituspaiva;
    }
}
