package com.exam3;

import java.util.Scanner;

public class Pelaaja {
    private int pelinumero;
    private String nimi;
    private String joukkue;
    private String pelipaikka;
    private int maalit;
    private int syotot;

    public Pelaaja() {
    }

    public Pelaaja(int pelinumero, String nimi, String joukkue, String pelipaikka, int maalit, int syotot) {
        this.pelinumero = pelinumero;
        this.nimi = nimi;
        this.joukkue = joukkue;
        this.pelipaikka = pelipaikka;
        this.maalit = maalit;
        this.syotot = syotot;
    }

    public int getPelinumero() {
        return pelinumero;
    }

    public void setPelinumero(int pelinumero) {
        this.pelinumero = pelinumero;
    }

    public String getNimi() {
        return nimi;
    }

    public void setNimi(String nimi) {
        this.nimi = nimi;
    }

    public String getJoukkue() {
        return joukkue;
    }

    public void setJoukkue(String joukkue) {
        this.joukkue = joukkue;
    }

    public String getPelipaikka() {
        return pelipaikka;
    }

    public void setPelipaikka(String pelipaikka) {
        this.pelipaikka = pelipaikka;
    }

    public int getMaalit() {
        return maalit;
    }

    public void setMaalit(int maalit) {
        this.maalit = maalit;
    }

    public int getSyotot() {
        return syotot;
    }

    public void setSyotot(int syotot) {
        this.syotot = syotot;
    }

    public void kysyTiedot(String vastaus) {
        Scanner input=new Scanner(System.in);
        this.setPelinumero(Integer.parseInt(vastaus));
        System.out.print("Anna pelaajan nimi: ");
        this.setNimi(input.nextLine());
        System.out.print("Anna pelaajan joukkue: ");
        this.setJoukkue(input.nextLine());
        System.out.print("Anna pelaajan pelipaikka: ");
        this.setPelipaikka(input.nextLine());
        System.out.print("Anna kauden maalit: ");
        this.setMaalit(Integer.parseInt(input.nextLine()));
        System.out.print("Anna kauden syötöt: ");
        this.setSyotot(Integer.parseInt(input.nextLine()));
        System.out.println();
    }
}
