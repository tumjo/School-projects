package com.exam4;

public class Kypara extends Tuote {
    private double koko;
    private String vari;

    public Kypara() {
    }

    public Kypara(double hinta, String kayttoonottopaiva, double koko, String vari) {
        super(hinta, kayttoonottopaiva);
        this.koko = koko;
        this.vari = vari;
    }

    public double getKoko() {
        return koko;
    }

    public void setKoko(double koko) {
        this.koko = koko;
    }

    public String getVari() {
        return vari;
    }

    public void setVari(String vari) {
        this.vari = vari;
    }

    @Override
    public String toString() {
        return "Kypara{" +
                "koko=" + koko +
                ", vari='" + vari + '\'' +
                '}' + super.toString();
    }
}
