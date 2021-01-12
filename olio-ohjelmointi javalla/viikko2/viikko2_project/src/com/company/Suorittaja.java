package com.company;

public class Suorittaja {
    private final int MAX = 5;
    private final int MAX_VIIKKOTEHTAVAPISTEET = 16;
    //final int MAX_KOEPISTEET = 20;
    private Opintosuoritukset[] suorittajat;
    private int lkm=0;

    public Suorittaja(){}

    public void lisaaSuoritukset(){
        if (lkm==0){
            suorittajat=new Opintosuoritukset[MAX];
        }
        else if (lkm>=10){
            return;
        }
        Opintosuoritukset s = new Opintosuoritukset();
        s.kysyTiedot();
        suorittajat[lkm]=s;
        lkm++;
    }
    public void tulostaArvosanat(){

        for(int i=0; i<lkm; i++) {
            int arvosana;
            System.out.print("Henkilö: " + suorittajat[i].getNimi() + ", Viikkotehtävien pisteet: " + suorittajat[i].getPisteetviikkotehtavista() + ", Kokeen pisteet: " + suorittajat[i].getPisteetkokeesta());
            if (suorittajat[i].getPisteetkokeesta()<10)
                arvosana = 0;
            else  if(suorittajat[i].getPisteetkokeesta()<12)
                arvosana = 1;
            else  if(suorittajat[i].getPisteetkokeesta()<14)
                arvosana = 2;
            else  if(suorittajat[i].getPisteetkokeesta()<16)
                arvosana = 3;
            else  if(suorittajat[i].getPisteetkokeesta()<18)
                arvosana = 4;
            else
                arvosana = 5;
            if (arvosana > 0 && ((double) suorittajat[i].getPisteetviikkotehtavista()/MAX_VIIKKOTEHTAVAPISTEET) >= 0.75)
                arvosana++;
            if (arvosana> 5)
                arvosana = 5;
            System.out.println(", Arvosana: " + arvosana);
        }
    }
}
