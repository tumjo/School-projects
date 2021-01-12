package com.company;

public class OpiskelijaUtils {

    public OpiskelijaUtils() {
    }

    public static String TarkastaTiedot(Opiskelija o){
        if(o.getOsoite()==null && o.getEtunimi()==null && o.getSukunimi()==null && o.getOpiskelijanumero()==null){
            return null;
        }
        if (!Character.isUpperCase(o.getEtunimi().charAt(0))) {
            String nimi = o.getEtunimi();
            o.setEtunimi(nimi.substring(0, 1).toUpperCase() + nimi.substring(1));
        }

        if (!Character.isUpperCase(o.getSukunimi().charAt(0))) {
            String snimi = o.getSukunimi();
            o.setSukunimi(snimi.substring(0, 1).toUpperCase() + snimi.substring(1));
        }


        for(int i=0; o.getOpiskelijanumero().length()>i; i++) {
            if(Character.isLetter(o.getOpiskelijanumero().charAt(i))) {
                return null;
            }
        }
        return o.toString();
    }
}
