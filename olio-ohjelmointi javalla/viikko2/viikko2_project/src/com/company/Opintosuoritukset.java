package com.company;

import java.util.Scanner;

public class Opintosuoritukset {
    private int pisteetviikkotehtavista;
    private int pisteetkokeesta;
    private String nimi;

    public Opintosuoritukset(){}

    public void setNimi(String nimi) {
        this.nimi = nimi;
    }

    public void setPisteetkokeesta(int pisteetkokeesta) {
        this.pisteetkokeesta = pisteetkokeesta;
    }

    public void setPisteetviikkotehtavista(int pisteetviikkotehtavista) {
        this.pisteetviikkotehtavista = pisteetviikkotehtavista;
    }

    public String getNimi() {
        return nimi;
    }

    public int getPisteetkokeesta() {
        return pisteetkokeesta;
    }

    public int getPisteetviikkotehtavista() {
        return pisteetviikkotehtavista;
    }

    public void kysyTiedot() {
        Scanner input = new Scanner(System.in);
        System.out.print("Anna nimi: ");
        setNimi(input.nextLine());
        System.out.print("Anna viikkotehtävien tehtäväpisteet: ");
        setPisteetviikkotehtavista(input.nextInt());
        System.out.print("Anna kokeen pisteet: ");
        setPisteetkokeesta(input.nextInt());
    }
}
