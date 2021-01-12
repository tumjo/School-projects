package com.company;


import java.util.ArrayList;

public class Solution2 {
    public static void main(String[] args) {
        ArrayList<Double> lista = new ArrayList<Double>();
        lista.add(100.5);
        lista.add(99.5);
        lista.add(255.3);
        lista.add(144.7);
        lista.add(1.6);

        for(double a : lista) {
            System.out.println(a);
        }
        System.out.print("LaskeYhteen: ");
        System.out.println(MathUtils.LaskeYhteen(lista)); // LaskeYhteen, ottaa vastaan listan desimaalilukuja, laskee ne yhteen sekä palauttaa yhteenlaskun tuloksen
        System.out.print("SuurinLuku: ");
        System.out.println(MathUtils.SuurinLuku(lista)); // SuurinLuku, ottaa vastaan listan desimaalilukujaja palauttaa suurimman
        System.out.print("LaskeKeskiarvo: ");
        System.out.println(MathUtils.LaskeKeskiarvo(lista)); // LaskeKeskiarvo, ottaa vastaan listan desimaalilukuja, laskee niiden keskiarvon ja palauttaa sen.

    }
}
