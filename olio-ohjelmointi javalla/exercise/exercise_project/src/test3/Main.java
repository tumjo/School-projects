package test3;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Takuukorjaus> tuotteet=new ArrayList<>();
        Scanner input=new Scanner(System.in);
        String vastaus;

        while(true){
            System.out.print("anna tuotekoodi: ");
            vastaus=input.nextLine();
            if(vastaus.equals("0")){
                break;
            }
            Takuukorjaus korjattava=new Takuukorjaus();
            korjattava.kysyTiedot(vastaus);
            tuotteet.add(korjattava);
        }
        System.out.print("Anna tuotenumero jonka tietoja halaut tarkastella: ");
        vastaus=input.nextLine();
        TakuuUtils.palautaTuotteenTakuuasiat(tuotteet, vastaus);

    }
}
