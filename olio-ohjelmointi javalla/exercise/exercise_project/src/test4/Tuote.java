package test4;

public class Tuote {
    private String nimi;
    private String hyllypaikka;
    private String koodi;
    private double hinta;

    public Tuote() {
    }

    public Tuote(String nimi, String hyllypaikka, String koodi, double hinta) {
        this.nimi = nimi;
        this.hyllypaikka = hyllypaikka;
        this.koodi = koodi;
        this.hinta = hinta;
    }

    public String getNimi() {
        return nimi;
    }

    public void setNimi(String nimi) {
        this.nimi = nimi;
    }

    public String getHyllypaikka() {
        return hyllypaikka;
    }

    public void setHyllypaikka(String hyllypaikka) {
        this.hyllypaikka = hyllypaikka;
    }

    public String getKoodi() {
        return koodi;
    }

    public void setKoodi(String koodi) {
        this.koodi = koodi;
    }

    public double getHinta() {
        return hinta;
    }

    public void setHinta(double hinta) {
        this.hinta = hinta;
    }
}
