package com.exam4;

public class Monot extends Tuote {
    private int koko;
    private double jaykkyys;

    public Monot() {
    }

    public Monot(double hinta, String kayttoonottopaiva, int koko, double jaykkyys) {
        super(hinta, kayttoonottopaiva);
        this.koko = koko;
        this.jaykkyys = jaykkyys;
    }

    public int getKoko() {
        return koko;
    }

    public void setKoko(int koko) {
        this.koko = koko;
    }

    public double getJaykkyys() {
        return jaykkyys;
    }

    public void setJaykkyys(double jaykkyys) {
        this.jaykkyys = jaykkyys;
    }

    @Override
    public String toString() {
        return "Monot{" +
                "koko=" + koko +
                ", jaykkyys=" + jaykkyys +
                '}' + super.toString();
    }
}
