package com.company2;

public class OmatJaYhteisetTilit {
    public Saastotili omaTili;
    public SuperSaastoTili yhteinenTili;

    public OmatJaYhteisetTilit(Saastotili omaTili, SuperSaastoTili yhteinenTili) {
        this.omaTili = new Saastotili(omaTili);
        this.yhteinenTili = new SuperSaastoTili(yhteinenTili);
    }

    public OmatJaYhteisetTilit() {

    }

    public Saastotili getOmaTili() {
        return omaTili;
    }

    public SuperSaastoTili getYhteinenTili() {
        return yhteinenTili;
    }

    public void tulostaTilienTiedot() {
        omaTili.tulostaTilinTiedot();
        yhteinenTili.tulostaTilinTiedot();
    }
}

