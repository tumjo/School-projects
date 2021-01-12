package com.company;

public class Henkilo {
    private String nimi;
    private String osoite;
    private String syntymaaika;

    public Henkilo(String nimi, String osoite, String syntymaaika) {
        this.nimi=nimi;
        this.osoite=osoite;
        this.syntymaaika=syntymaaika;
    }

    // metodi luokan perillisille
    protected String getHenkilonTiedot() {
        return nimi + ", " + osoite + ", " + syntymaaika;
    }
}
