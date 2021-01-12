package com.company2;

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

    // Kopioalustaja
    public Tili(Tili t) {
        this.tilinumero = t.tilinumero;
        this.omistaja = t.omistaja;
        this.saldoEuroa = t.saldoEuroa;
        this.vuosikorko = t.vuosikorko;
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

    public void setVuosikorko(double vuosikorko) throws ArithmeticException{
        if(vuosikorko<0){
            throw new ArithmeticException("Vuosikorko ei voi olla negatiivnen");
        }
        this.vuosikorko = vuosikorko;
    }

    public abstract double laskeVuosiKorkotuotto();

    public abstract void tulostaTilinTiedot();
}
