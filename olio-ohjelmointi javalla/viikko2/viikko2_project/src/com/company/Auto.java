package com.company;

import java.util.Scanner;

public class Auto {
    private String rekisterinumero;
    private String merkki;
    private int vuosimalli;
    private String malli;


    // Default constructor
    public Auto(){
    }
    // Parameterized constructor
    public Auto(String rekisterinumero, String merkki, int vuosimalli, String malli){
        this.rekisterinumero=rekisterinumero;
        this.merkki=merkki;
        this.vuosimalli=vuosimalli;
        this.malli=malli;
    }
    // Copy constructor
    public Auto(Auto kopio){
        rekisterinumero=kopio.rekisterinumero;
        merkki=kopio.merkki;
        vuosimalli=kopio.vuosimalli;
        malli=kopio.malli;
    }

    public void setRekisterinumero(String rekisterinumero) {
        if(rekisterinumero.length()>7 || !rekisterinumero.contains("-")){
            this.rekisterinumero="unknown";
        }
        else {
            this.rekisterinumero = rekisterinumero;
        }

    }

    public String getRekisterinumero() {
        return rekisterinumero;
    }

    public void setMerkki(String merkki) {
        this.merkki = merkki;
    }

    public String getMerkki() {
        return merkki;
    }

    public void setVuosimalli(int vuosimalli) {
        if (vuosimalli>2020 || vuosimalli < 1900 ) {
            this.vuosimalli=1900;
        }else {
            this.vuosimalli = vuosimalli;
        }
    }

    public int getVuosimalli() {
        return vuosimalli;
    }

    public void setMalli(String malli) {
        this.malli = malli;
    }

    public String getMalli() {
        return malli;
    }

    public void kysyTiedot() {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna rekisterinumero: ");
        setRekisterinumero(input.nextLine());
        System.out.print("Anna merkki: ");
        setMerkki(input.nextLine());
        System.out.print("Anna vuosimalli: ");
        setVuosimalli(input.nextInt());
        System.out.print("Anna malli: ");
        input.nextLine();
        setMalli(input.nextLine());
    }

    @Override
    public String toString() {
        return "Auto rekisterinumerolla " + rekisterinumero + " on merkiltään " + merkki + ". Se on vuosimallia " + vuosimalli + ". Malliltaan auto on " + malli + ".";
    }
}
