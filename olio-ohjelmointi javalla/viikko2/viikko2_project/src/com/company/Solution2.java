package com.company;

// Käytetään luokkaa Auto
public class Solution2 {
    public static void main(String[] args) {
        System.out.println("Moi");

        // Kokeilut. Tee luokalle get ja set -metodit
        // Kokeilut. Tee luokalle vähintään kolme(3) erilaista muodostinta.
        Auto ajoneuvo = new Auto("AAA-111", "Volksvagen", 1999, "Passat");
        System.out.println("Olion ajoneuvo ominaisuus merkki: " + ajoneuvo.getMerkki());
        Auto ajoneuvo2 = new Auto(ajoneuvo);
        System.out.println("Olion ajoneuvo2 ominaisuus malli: " + ajoneuvo2.getMalli());
        Auto ajoneuvo3 = new Auto();
        // Kokeilut. Tarkista vuosimallin set-metodissa, että vuosimalli on >= 1900 ja pienempi kuin tämä kuluva vuosi. Jos ei ole, niin vuosimalliksi laitetaan 1900
        ajoneuvo3.setVuosimalli(1901);
        System.out.println(ajoneuvo3.getVuosimalli());
        ajoneuvo3.setVuosimalli(1899);
        System.out.println(ajoneuvo3.getVuosimalli());
        ajoneuvo3.setVuosimalli(2021);
        System.out.println(ajoneuvo3.getVuosimalli());
        // Kokeilut. Tarkista rekisterinumeron set-metodissa, että rekisterinumeron max pituus on 7 merkkiä ja sisältää väliviivan. Jos ehto ei täyty laita rekisterinumeroksi teksti "unknown"
        ajoneuvo3.setRekisterinumero("m1");
        System.out.println(ajoneuvo3.getRekisterinumero());
        ajoneuvo3.setRekisterinumero("m1sadsddas");
        System.out.println(ajoneuvo3.getRekisterinumero());
        ajoneuvo3.setRekisterinumero("m1sadgfg-sddas");
        System.out.println(ajoneuvo3.getRekisterinumero());
        ajoneuvo3.setRekisterinumero("abc-123");
        System.out.println(ajoneuvo3.getRekisterinumero());
        // Kokeilut. Tee luokalle kysyTiedot -metodi, jossa kysyt luokan attribuutteihin arvot.
        Auto ajoneuvo4 = new Auto();
        ajoneuvo4.kysyTiedot();
        // Kokeilut. Tee luokalle toString-metodi, joka palauttaa attribuuttien tiedot merkkijonona ja "siistityssä" muodossa eli muokkaa oletuspohjaa siistimmäksi.
        System.out.println(ajoneuvo4.toString());
    }
}
