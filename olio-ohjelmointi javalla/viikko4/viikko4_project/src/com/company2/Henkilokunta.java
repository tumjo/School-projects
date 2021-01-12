package com.company2;

import java.util.Scanner;

public class Henkilokunta extends Henkilo {
    private String tyontekijanumero;
    private String toimipaikka;
    private String titteli;

    Henkilokunta() {

    }

    Henkilokunta(String nimi, String osoite, String syntymaaika, String tyontekijanumero, String toimipaikka, String titteli) {
        super(nimi, osoite, syntymaaika);
        this.tyontekijanumero = tyontekijanumero;
        this.toimipaikka = toimipaikka;
        this.titteli = titteli;
    }

    String tulostaHenkilokunta(){
        return super.getHenkilonTiedot() + ", " + tyontekijanumero + ", " + toimipaikka + ", " + titteli;
    }

    @Override
    public void kysyTiedot() {
        super.kysyTiedot();
        Scanner input = new Scanner(System.in);
        System.out.print("Anna tyontekijanumero: ");
        tyontekijanumero=input.nextLine();
        System.out.print("Anna toimipaikka: ");
        toimipaikka=input.nextLine();
        System.out.print("Anna titteli: ");
        titteli=input.nextLine();
    }
}
