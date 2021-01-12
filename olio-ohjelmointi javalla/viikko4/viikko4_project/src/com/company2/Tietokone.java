package com.company2;

public class Tietokone extends Tuote {
    private String merkki;
    private String malli;

    public Tietokone() {
    }

    public Tietokone(final String merkki, final String malli) {
        this.merkki = merkki;
        this.malli = malli;
    }

    public Tietokone(final String merkki, final String malli, final String tuotenumero) {
        super(tuotenumero);
        this.merkki = merkki;
        this.malli = malli;
    }

    public Tietokone(final String merkki, final String malli, final String tuotenumero, final int maara, final int tuotepaikka) {
        super(tuotenumero, maara, tuotepaikka);
        this.merkki = merkki;
        this.malli = malli;
    }

    public String getMerkki() {
        return merkki;
    }

    public void setMerkki(String merkki) {
        this.merkki = merkki;
    }

    public String getMalli() {
        return malli;
    }

    public void setMalli(String malli) {
        this.malli = malli;
    }

    // Korvaa (override) Tuote-luokan getTuotepaikka-metodi Tietokone-luokassa. Tee ohjelma, joka tulostaa tuotteiden tiedot uusilla tuotepaikoilla.
    @Override
    public int getTuotepaikka() {
        final int tuotepaikka=super.getTuotepaikka();
        if (tuotepaikka<10){
            return tuotepaikka+10;
        }
        else if(tuotepaikka <= 100){
            return  tuotepaikka +30;
        }
        else if (tuotepaikka>100) {
            return tuotepaikka+500;
        }
        else {
            // you re not supposed to be here
            return tuotepaikka;
        }
    }

    @Override
    public String toString() {
        return super.toString() + " " + merkki + " " + malli;
    }
}
