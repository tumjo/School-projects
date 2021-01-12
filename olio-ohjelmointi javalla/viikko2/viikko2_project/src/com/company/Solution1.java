package com.company;

// Käytetään luokkaa Opiskelija
public class Solution1 {
    public static void main(String[] args) {
        Opiskelija henkilo = new Opiskelija();
        henkilo.setEtunimi("Liisa");
        System.out.println(henkilo.getEtunimi());

        Opiskelija henkilo2 = new Opiskelija("Matti", "Meikäläinen", 123456, "Esimerkkikatu 1, 33333 City");
        System.out.println(henkilo2.toString());
    }
}
