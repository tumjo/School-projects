package com.company;

import java.util.Scanner;

public class Opiskelija {
    private String etunimi;
    private String sukunimi;
    private String opiskelijanumero;
    private String osoite;

    public Opiskelija(){

    }
    public Opiskelija(String etunimi, String sukunimi, String opiskelijanumero, String osoite){
        this.etunimi=etunimi;
        this.sukunimi=sukunimi;
        this.opiskelijanumero=opiskelijanumero;
        this.osoite=osoite;
    }

    public String getEtunimi() {
        return etunimi;
    }

    public void setEtunimi(String etunimi) {
        this.etunimi = etunimi;
    }

    public String getSukunimi() {
        return sukunimi;
    }

    public void setSukunimi(String sukunimi) {
        this.sukunimi = sukunimi;
    }

    public String getOpiskelijanumero(){
        return opiskelijanumero;
    }

    public void setOpiskelijanumero(String opiskelijanumero){
        this.opiskelijanumero=opiskelijanumero;
    }

    public String getOsoite(){
        return osoite;
    }

    public void setOsoite(String osoite) {
        this.osoite = osoite;
    }

    public void kysyTiedot() {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna etunimi: ");
        setEtunimi(input.nextLine());
        System.out.print("Anna sukunimi: ");
        setSukunimi(input.nextLine());
        System.out.print("Anna opiskelijanumero: ");
        setOpiskelijanumero(input.nextLine());
        System.out.print("Anna osoite: ");
        setOsoite(input.nextLine());
        String txt=OpiskelijaUtils.TarkastaTiedot(this);
        if (txt!=null){
            System.out.println(txt);
        }
        else {
            System.out.println("Virhe. Palautettiin NULL");
        }
    }

    @Override
    public String toString() {
        return etunimi + " " + sukunimi + " opiskelijanumerolla " + opiskelijanumero + " asuu osoitteessa " + osoite;
    }
}
