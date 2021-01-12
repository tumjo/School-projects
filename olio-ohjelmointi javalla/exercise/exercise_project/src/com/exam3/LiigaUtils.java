package com.exam3;

import java.util.ArrayList;

public class LiigaUtils {

    public static ArrayList<Pelaaja> palautaPelaajat(String joukkue, ArrayList<Pelaaja> a){
        ArrayList<Pelaaja> rakenne =new ArrayList<>();
        for(Pelaaja x : a){
            if(x.getJoukkue().equals(joukkue)){
                rakenne.add(x);
            }
        }
        return rakenne;
    }
    public static int maalit(ArrayList<Pelaaja> a){
        int yhteensa=0;
        for(Pelaaja x : a){
            yhteensa+=x.getMaalit();
        }
        return yhteensa;
    }
}
