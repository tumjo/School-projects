package com.exam5;

public class Tuote extends TuoteBase{
    private String kuvaus;
    private double myyntihinta;
    private boolean varastossa;

    public String getKuvaus() {
        return kuvaus;
    }
    public void setKuvaus(String kuvaus) {
        this.kuvaus = kuvaus;
    }
    public double getMyyntihinta() {
        return myyntihinta;
    }
    public void setMyyntihinta(double myyntihinta) {
        this.myyntihinta = myyntihinta;
    }
    public boolean isVarastossa() {
        return varastossa;
    }
    public void setVarastossa(boolean varastossa) {
        this.varastossa = varastossa;
    }

    @Override
    public void tulostaTuotteenTiedot() {
        System.out.print("Tuotteen nimi: " + getNimi() + " Tuotteen sarjanumero: " + getSarjanumero() + " Tuotteen kuvaus: " + getKuvaus() + " Tuotteen myyntihinta " + getMyyntihinta() + " € Onko tuotetta varastossa: ");
        if(isVarastossa()){
            System.out.print("Kyllä");
        }
        else {
            System.out.print("Ei");
        }
        System.out.println();
    }
}
