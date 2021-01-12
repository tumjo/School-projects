package test3;

import java.util.Scanner;

public class Takuukorjaus {
    private String tuotekoodi;
    private String kuvaus;
    private String ratkaisu;
    private double kustannukset;


    public Takuukorjaus() {
    }

    public String getTuotekoodi() {
        return tuotekoodi;
    }

    public void setTuotekoodi(String tuotekoodi) {
        this.tuotekoodi = tuotekoodi;
    }

    public String getKuvaus() {
        return kuvaus;
    }

    public void setKuvaus(String kuvaus) {
        this.kuvaus = kuvaus;
    }

    public String getRatkaisu() {
        return ratkaisu;
    }

    public void setRatkaisu(String ratkaisu) {
        this.ratkaisu = ratkaisu;
    }

    public double getKustannukset() {
        return kustannukset;
    }

    public void setKustannukset(double kustannukset) {
        this.kustannukset = kustannukset;
    }

    public void kysyTiedot(String vastaus){
        this.setTuotekoodi(vastaus);
        Scanner input=new Scanner(System.in);
        System.out.print("Anna kuvaus: ");
        this.setKuvaus(input.nextLine());
        System.out.print("Anna ratkaisu: ");
        this.setRatkaisu(input.nextLine());
        System.out.print("Anna kustannukset: ");
        this.setKustannukset(Integer.parseInt(input.nextLine()));
        System.out.println();
    }
}
