package com.company2;

public class Tuote {
    private String tuotenumero;
    private int tuotepaikka;
    private int maara;

    public Tuote() {
    }

    public Tuote(final String tuotenumero) {
        this.tuotenumero = tuotenumero;
    }

    public Tuote(final String tuotenumero, final int maara, final int tuotepaikka) {
        this.tuotenumero = tuotenumero;
        this.tuotepaikka = tuotepaikka;
        this.maara = maara;
    }

    public String getTuotenumero() {
        return tuotenumero;
    }

    public int getTuotepaikka() {
        return tuotepaikka;
    }

    public int getMaara() {
        return maara;
    }

    public void setTuotepaikka(int tuotepaikka) {
        this.tuotepaikka = tuotepaikka;
    }

    public void setMaara(int maara) {
        this.maara = maara;
    }

    @Override
    public String toString() {
        return tuotenumero + " " + tuotepaikka + " " + maara;
    }
}
