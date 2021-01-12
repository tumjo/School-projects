package com.company2;

import java.util.ArrayList;

public class Solution4 {

    public static void main(String[] args) {
        // Käytä edellisen tehtävän luokkarakennetta ja tee ohjelma, jolla on LISTA Tietokone-luokan olioita tiedoilla
        ArrayList<Tietokone> tietokoneet = new ArrayList<Tietokone>();
        Tietokone t1=new Tietokone("Asus", "ER443", "212232", 3, 12);
        tietokoneet.add(t1);
        Tietokone t2=new Tietokone("Lenovo", "HH544", "3233", 21, 15);
        tietokoneet.add(t2);
        Tietokone t3=new Tietokone("Fujitsu", "3323F", "9888", 5, 2);
        tietokoneet.add(t3);
        Tietokone t4=new Tietokone("IBM", "IBM3444", "343", 2, 150);
        tietokoneet.add(t4);

        for(Tietokone t : tietokoneet) {
            System.out.println("Merkki: " + t.getMerkki() + ", Malli: " + t.getMalli() + ", Tuotenumero: " + t.getTuotenumero() + ", Tuotepaikka: " + t.getTuotepaikka() + ", Maara: " + t.getMaara());
        }
    }
}
