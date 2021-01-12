package com.company;

public abstract class Tili {
    private String tilinumero;
    private String omistaja;
    private double saldoEuroa;
    private double vuosikorko;

    public Tili(String tilinumero, String omistaja, double saldoEuroa, double vuosikorko) {
        this.tilinumero = tilinumero;
        this.omistaja = omistaja;
        this.saldoEuroa = saldoEuroa;
        this.vuosikorko = vuosikorko;
    }

    public Tili() {
    }

    public String getTilinumero() {
        return tilinumero;
    }

    public void setTilinumero(String tilinumero) {
        this.tilinumero = tilinumero;
    }

    public String getOmistaja() {
        return omistaja;
    }

    public void setOmistaja(String omistaja) {
        this.omistaja = omistaja;
    }

    public double getSaldoEuroa() {
        return saldoEuroa;
    }

    public void setSaldoEuroa(double saldoEuroa) {
        this.saldoEuroa = saldoEuroa;
    }

    public double getVuosikorko() {
        return vuosikorko;
    }

    public void setVuosikorko(double vuosikorko) {
        this.vuosikorko = vuosikorko;
    }

    public abstract double laskeVuosiKorkotuotto();

    public abstract void tulostaTilinTiedot();
}
