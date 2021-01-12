package com.exam4;

public class Tuote {
    private double hinta;
    private String kayttoonottopaiva;

    public Tuote() {
    }

    public Tuote(double hinta, String kayttoonottopaiva) {
        this.hinta = hinta;
        this.kayttoonottopaiva = kayttoonottopaiva;
    }

    public double getHinta() {
        return hinta;
    }

    public void setHinta(double hinta) {
        this.hinta = hinta;
    }

    public String getKayttoonottopaiva() {
        return kayttoonottopaiva;
    }

    public void setKayttoonottopaiva(String kayttoonottopaiva) {
        this.kayttoonottopaiva = kayttoonottopaiva;
    }

    @Override
    public String toString() {
        return " Käyttöönotettu: " + kayttoonottopaiva + " ja hinta: " + hinta + " euroa per pv.";
    }
}
