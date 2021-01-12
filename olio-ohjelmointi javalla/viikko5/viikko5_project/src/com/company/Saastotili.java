package com.company;

public class Saastotili extends Tili {


    public Saastotili(String tilinumero, String omistaja, double saldoEuroa, double vuosikorko) {
        super(tilinumero, omistaja, saldoEuroa, vuosikorko);
    }

    public Saastotili() {
    }

    @Override
    public double laskeVuosiKorkotuotto() {

        return getVuosikorko()/100*getSaldoEuroa();
    }

    @Override
    public void tulostaTilinTiedot() {
        String txt=getOmistaja() + ": Saastotilin saldo on " + getSaldoEuroa() + " €, korkoprosentilla " + getVuosikorko() + " vuosikorko on " + laskeVuosiKorkotuotto() + " €";
        System.out.println(txt);
    }
}
