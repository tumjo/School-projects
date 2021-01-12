package com.exam5;

public abstract class TuoteBase {
    private String nimi;
    private String sarjanumero;


    public TuoteBase() {
    }

    public String getNimi() {
        return nimi;
    }

    public void setNimi(String nimi) {
        this.nimi = nimi;
    }

    public String getSarjanumero() {
        return sarjanumero;
    }

    public void setSarjanumero(String sarjanumero) {
        this.sarjanumero = sarjanumero;
    }

    public abstract void tulostaTuotteenTiedot();
}
