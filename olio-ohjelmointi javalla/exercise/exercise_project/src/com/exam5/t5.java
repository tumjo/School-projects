package com.exam5;

import java.util.ArrayList;

public class t5 {
    public static void main(String[] args) {
        System.out.println("Tervetuloa verkkokauppaan!");
        Canon canon = new Canon();
        Genelec genelec = new Genelec();
        ArrayList<Tuote> canonTuotteet = new ArrayList<>();
        ArrayList<Tuote> genelecTuotteet = new ArrayList<>();
        System.out.println("Haetaan Canon tuotteet ja tulostetaan kaikki tiedot...");
        canonTuotteet=canon.getTuoteTiedot();
        for (Tuote x : canonTuotteet){
            x.tulostaTuotteenTiedot();
        }
        System.out.println("Haetaan Genelec tuotteet ja tulostetaan kaikki tiedot...");
        genelecTuotteet=genelec.getTuoteTiedot();
        for (Tuote x : genelecTuotteet){
            x.tulostaTuotteenTiedot();
        }


    }
}
