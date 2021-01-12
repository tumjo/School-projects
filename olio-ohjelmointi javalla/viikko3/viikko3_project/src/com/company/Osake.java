package com.company;

import java.text.DecimalFormat;
import java.util.Scanner;

public class Osake {
    private String nimi;
    private double ostohinta;
    private double nykyinenarvo;
    private static double kasvuprosentti;
    private static int ajanjaksoVuosina;
    private static double osakesalkunTuotto=0;

    public Osake() {
    }

    public static double getKasvuprosentti() {
        return kasvuprosentti;
    }

    public static void setKasvuprosentti(double kasvuprosentti) {
        Osake.kasvuprosentti = kasvuprosentti;
    }

    public static int getAjanjaksoVuosina() {
        return ajanjaksoVuosina;
    }

    public static void setAjanjaksoVuosina(int ajanjaksoVuosina) {
        Osake.ajanjaksoVuosina = ajanjaksoVuosina;
    }

    public static double getOsakesalkunTuotto() {
        return osakesalkunTuotto;
    }

    private double LaskeTuottoYhdelleVuodelle() {
        return (kasvuprosentti/100)*nykyinenarvo;

    }
    public void kysyTiedot() {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna osakkeen nimi: ");
        nimi=input.nextLine();
        System.out.print("Anna osakkeen ostohinta: ");
        nykyinenarvo=ostohinta=input.nextDouble();
        System.out.println("Osake lisätty listaan!");
    }
    public void tulostaArvo() {
        DecimalFormat fmt = new DecimalFormat("0.00");
        for(int i=0; i<ajanjaksoVuosina; i++) {
            double tuotto=LaskeTuottoYhdelleVuodelle();
            nykyinenarvo=nykyinenarvo+tuotto;
            osakesalkunTuotto=osakesalkunTuotto+tuotto;
        }
        System.out.println("Osakkeen " + nimi + " arvo on kasvanut " + ajanjaksoVuosina + " vuodessa " + kasvuprosentti + " prosentin korolla " + fmt.format((nykyinenarvo-ostohinta)) + " euroa. Osakkeen nykyinen arvo on " + fmt.format(nykyinenarvo) + " euroa.");
    }
}
