package com.exam5;

import java.util.ArrayList;

public class Genelec implements TietovarastoNouto {
    @Override
    public ArrayList<Tuote> getTuoteTiedot() {
        ArrayList<Tuote> tuotteet = new ArrayList<>();
        Tuote tuote1 = new Tuote();
        tuote1.setNimi("Gen1");
        tuote1.setSarjanumero("123a");
        tuote1.setKuvaus("Kaiutin pro1");
        tuote1.setMyyntihinta(620.60);
        tuote1.setVarastossa(true);
        tuotteet.add(tuote1);

        Tuote tuote2 = new Tuote();
        tuote2.setNimi("Gen2");
        tuote2.setSarjanumero("123b");
        tuote2.setKuvaus("Kaiutin pro2");
        tuote2.setMyyntihinta(820.80);
        tuote2.setVarastossa(true);
        tuotteet.add(tuote2);

        Tuote tuote3 = new Tuote();
        tuote3.setNimi("Gen3");
        tuote3.setSarjanumero("123c");
        tuote3.setKuvaus("Kaiutin pro3");
        tuote3.setMyyntihinta(1200);
        tuote3.setVarastossa(false);
        tuotteet.add(tuote3);

        return tuotteet;
    }
}
