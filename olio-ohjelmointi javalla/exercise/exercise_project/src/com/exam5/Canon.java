package com.exam5;

import java.util.ArrayList;

public class Canon implements TietovarastoNouto {
    @Override
    public ArrayList<Tuote> getTuoteTiedot() {
        ArrayList<Tuote> tuotteet = new ArrayList<>();
        Tuote tuote1 = new Tuote();
        tuote1.setNimi("Canon1");
        tuote1.setSarjanumero("987a");
        tuote1.setKuvaus("Hyvä kamera");
        tuote1.setMyyntihinta(620.60);
        tuote1.setVarastossa(true);
        tuotteet.add(tuote1);

        Tuote tuote2 = new Tuote();
        tuote2.setNimi("Canon2");
        tuote2.setSarjanumero("987b");
        tuote2.setKuvaus("Todella hyvä kamera");
        tuote2.setMyyntihinta(820.80);
        tuote2.setVarastossa(false);
        tuotteet.add(tuote2);

        Tuote tuote3 = new Tuote();
        tuote3.setNimi("Canon3");
        tuote3.setSarjanumero("987c");
        tuote3.setKuvaus("Paras kamera");
        tuote3.setMyyntihinta(1200);
        tuote3.setVarastossa(true);
        tuotteet.add(tuote3);

        return tuotteet;
    }
}
