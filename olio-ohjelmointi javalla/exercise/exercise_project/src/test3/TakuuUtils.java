package test3;

import java.util.ArrayList;

public class TakuuUtils {

    public static void palautaTuotteenTakuuasiat(ArrayList<Takuukorjaus> a, String tuoteNum){
        for(Takuukorjaus tuote : a){
            if(tuote.getTuotekoodi().equals(tuoteNum)){
                System.out.println(tuote.getTuotekoodi() + " " + tuote.getKuvaus() + " " + tuote.getRatkaisu() + " " + tuote.getKustannukset());
            }
        }
    }
}
