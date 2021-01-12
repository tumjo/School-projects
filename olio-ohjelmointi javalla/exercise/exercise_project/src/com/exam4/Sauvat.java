package com.exam4;

public class Sauvat extends Tuote {
    private double pituus;

    public Sauvat() {
    }

    public Sauvat(double hinta, String kayttoonottopaiva, double pituus) {
        super(hinta, kayttoonottopaiva);
        this.pituus = pituus;
    }

    public double getPituus() {
        return pituus;
    }

    public void setPituus(double pituus) {
        this.pituus = pituus;
    }

    @Override
    public String toString() {
        return "Sauvat{" +
                "pituus=" + pituus +
                '}' + super.toString();
    }

}
