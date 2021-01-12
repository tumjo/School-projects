package com.company;

public class Henkilokunta extends Henkilo {
    private String tyontekijanumero;
    private String toimipaikka;
    private String titteli;

    Henkilokunta(String nimi, String osoite, String syntymaaika, String tyontekijanumero, String toimipaikka, String titteli) {
        super(nimi, osoite, syntymaaika);
        this.tyontekijanumero = tyontekijanumero;
        this.toimipaikka = toimipaikka;
        this.titteli = titteli;
    }

    String tulostaHenkilokunta(){
        return super.getHenkilonTiedot() + ", " + tyontekijanumero + ", " + toimipaikka + ", " + titteli;
    }
}
