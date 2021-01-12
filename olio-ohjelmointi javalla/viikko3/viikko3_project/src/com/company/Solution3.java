package com.company;

public class Solution3 {
    public static void main(String[] args) {
        Opiskelija henkilo = new Opiskelija();
        henkilo.setEtunimi("Liisa");
        System.out.println(henkilo.getEtunimi());
        Opiskelija henkilo2 = new Opiskelija("Matti", "Meikäläinen", "123456", "Esimerkkikatu 1, 33333 City");
        System.out.println(henkilo2.toString());

        /*  Tee ohjelma, joka kysyy opiskelijan tiedot sekä tarkastaa ne.
            Jos tarkastus ei mene läpi, eli tarkastus palauttaa arvon null,
            ilmoitetaan virheestä, muutoin tulostetaan opiskelijan tiedot.
        */
        System.out.println(henkilo.getOsoite());
        System.out.println(henkilo.getOpiskelijanumero());
        Opiskelija henkilo3 = new Opiskelija();
        henkilo3.kysyTiedot();  // Opiskelija luokan kysyTiedot metodi kutsuu luokan OpiskelijaUtils staattista metodia TarkastaTiedot



    }
}
