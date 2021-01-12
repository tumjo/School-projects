package com.company;


import java.util.*;

public class Solution4 {
    // Lotto on numeroveikkaus, jossa arvotaan seitsemän (7) numeroa väliltä yksi (1) ja neljäkymmentä (40). Jokainen numero voi ilmentyä vain kerran.
    private static final int NUMEROMAARA = 7;
    private static final int MAX = 40;
    private static final int MIN = 1;

    public static void main(String[] args) {

        int[] omatNumerot = new int[NUMEROMAARA];
        int[] arvotutNumerot = new int[NUMEROMAARA];
        List<Integer> oikein=new ArrayList<>();
        boolean[] omatSisaltaa = new boolean[MAX];
        boolean[] arvotutSisaltaa = new boolean[MAX];
        int oikeinYhteensa;
        boolean onPeli = true;
        Scanner input = new Scanner(System.in);
        String vastaus;
        arvoRivi(arvotutSisaltaa, arvotutNumerot);
        System.out.print("Lottorivi on: ");
        tulostaRivi(arvotutNumerot);
        while(onPeli) {
            // Set 0
            oikeinYhteensa=0;
            // Clear list
            oikein.clear();
            // Assign all the elements of boolean array to false
            Arrays.fill(omatSisaltaa, false);
            System.out.print("Haluatko arpoa rivin (k= kyllä, e = ei): ");
            vastaus=input.nextLine();
            if (vastaus.equals("k")) {
                suoritaArpominen(omatSisaltaa, omatNumerot);
                int j = 0;
                for (int i = 0; i < MAX; i++) {
                    if (omatSisaltaa[i] && arvotutSisaltaa[i]) {
                        oikeinYhteensa++;
                        oikein.add(i + 1);
                        j++;
                    }
                }
                System.out.print("Oikein oli " + oikeinYhteensa + " kpl, jotka olivat ");
                for (int numero : oikein) {
                    System.out.print(numero + " ");
                }
                System.out.println();
            } else if (vastaus.equals("e")) {
                System.out.println("Kiitos ja hei hei!");
                onPeli=false;
            }
        }
    }

    private static void suoritaArpominen(boolean[] omatSisaltaa, int[] omatNumerot) {
        arvoRivi(omatSisaltaa, omatNumerot);
        System.out.print("Ohjelma arpoi rivin: ");
        tulostaRivi(omatNumerot);
    }


    private static void arvoRivi(boolean[] sisaltaa, int[] numerot) {
        Scanner input = new Scanner(System.in);
        Random randomNumero = new Random();
        int arvottuNumero;
        for (int i = 0; i < NUMEROMAARA; i++) {
            while (true) {
                arvottuNumero = randomNumero.nextInt(MAX - MIN+1) + MIN;
                if (!sisaltaa[(arvottuNumero - 1)]) {
                    sisaltaa[arvottuNumero - 1] = true;
                    numerot[i] = arvottuNumero;
                    break;
                }
            }
        }
    }

    private static void tulostaRivi(int[] arvotutNumerot) {
        for (int j=0; j < NUMEROMAARA; j++) {
            if(j!=(NUMEROMAARA-1)){
                System.out.print(arvotutNumerot[j] + ",");

            }else{
                System.out.println(arvotutNumerot[j]);
            }
        }
    }
}
