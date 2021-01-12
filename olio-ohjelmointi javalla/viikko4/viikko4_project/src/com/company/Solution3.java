package com.company;

public class Solution3 {
    public static void main(String[] args) {
        // Muista varmistaa, että jos alustajassa syötetään yliluokan tietoja, niin ne välitetään yliluokan alustajalle.
        // Tee ohjelma, joka luo KAKSI Tietokone-luokan oliota ja TÄYTTÄÄ KAIKKI TIEDOT ALUSTAJIA KÄYTTÄEN (tietoja ei tarvitse kysyä käyttäjältä, voit keksiä ne itse).
        Tietokone t1=new Tietokone("Dell", "a1", "a123456abc", 10, 13);
        Tietokone t2=new Tietokone("Asus", "UltraBook", "ca1231ab", 4, 11 );
        // käytetään toStringiä koska tehtävänanto ei määritellyt kuinka tulostus toteutetaan.
        System.out.println(t1.toString());
        System.out.println(t2.toString());

        //KOKEILU
        //Tietokone t3=new Tietokone("Asus", "UltraBook", "ca1231ab" );
        //t2.setMaara(2);
        //t2.setTuotepaikka(12);
        //System.out.println(t3.toString());
    }
}
