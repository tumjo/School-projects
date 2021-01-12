package com.exam4;

public class Sukset extends Tuote {
    private double pituus;
    private String merkki;

    public Sukset() {
    }

    public Sukset(double hinta, String kayttoonottopaiva, double pituus, String merkki) {
        super(hinta, kayttoonottopaiva);
        this.pituus = pituus;
        this.merkki = merkki;
    }

    public double getPituus() {
        return pituus;
    }

    public void setPituus(double pituus) {
        this.pituus = pituus;
    }

    public String getMerkki() {
        return merkki;
    }

    public void setMerkki(String merkki) {
        this.merkki = merkki;
    }

    @Override
    public String toString() {
        return "Sukset{" +
                "pituus=" + pituus +
                ", merkki='" + merkki + '\'' +
                '}' + super.toString();
    }
}
