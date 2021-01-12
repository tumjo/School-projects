package com.company;

public class SuperSaastoTili extends Tili {

    public SuperSaastoTili(String tilinumero, String omistaja, double saldoEuroa, double vuosikorko) {
        super(tilinumero, omistaja, saldoEuroa, vuosikorko);
    }

    public SuperSaastoTili() {
    }

    @Override
    public double laskeVuosiKorkotuotto() {
        if(getSaldoEuroa()<=10000){
            return getVuosikorko()/100*getSaldoEuroa();
        }
        else if(getSaldoEuroa()>10000){
            return (getVuosikorko()/100*10000)+((getVuosikorko()+3.0)/100*(getSaldoEuroa()-10000));
        }
        else {
            // you re not supposed to be here
            return 0;
        }

    }

    @Override
    public void tulostaTilinTiedot() {
        String txt=getOmistaja() + ": Supersaastotilin saldo on " + getSaldoEuroa() + " €, korkoprosentilla " + getVuosikorko() + " vuosikorko on " + laskeVuosiKorkotuotto() + " €";
        System.out.println(txt);
    }
}
