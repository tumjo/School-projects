package com.company;


// Käytetään luokkia Suorittaja ja Opintosuoritukset
public class Solution3 {
    public static void main(String[] args) {
        // Kysytään 5 henkilön nimi ja koepisteet
        final int MAX = 5;
        Suorittaja oppilas = new Suorittaja();
        for(int i =0;i<MAX; i++){
            oppilas.lisaaSuoritukset();
        }
        oppilas.tulostaArvosanat();

    }
}
