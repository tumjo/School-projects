package com.company;

import java.util.ArrayList;

public class MathUtils {
    public MathUtils(){

    }
    public static double LaskeYhteen(ArrayList<Double> lista) {
        double summa=0;
        for(double luku : lista) {
            summa += luku;
        }
        return summa;
    }

    public static double SuurinLuku(ArrayList<Double> lista) {
        double suurin = Double.MIN_VALUE;
        for(double luku : lista) {
            if (suurin<luku){
                suurin=luku;
            }
        }
        return suurin;
    }

    public static double LaskeKeskiarvo(ArrayList<Double> lista) {
        return MathUtils.LaskeYhteen(lista)/lista.size();
    }
}
