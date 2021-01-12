package com.company;

public class Solution1 {

    public static void main(String[] args) {
        System.out.println("Luodan opiskelija...");
        Opiskelija mallioppilas = new Opiskelija("Matti", "Osoite 1234", "4.9.94", 13144, "1.6.2020");
        System.out.println("tulostaOpiskelija: " +  mallioppilas.tulostaOpiskelija());
        System.out.println("Luodan henkilokunta...");
        Henkilokunta mallihenkilokunta = new Henkilokunta("Liisa", "Osoite 123", "4.9.90", "ABC123", "Helsinki", "Yliopettaja");
        System.out.println("tulostaHenkilokunta: " +  mallihenkilokunta.tulostaHenkilokunta());
    }
}
