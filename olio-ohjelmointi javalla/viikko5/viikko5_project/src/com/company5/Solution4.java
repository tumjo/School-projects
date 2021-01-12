package com.company5;

import java.util.Scanner;

public class Solution4 {
    public static void main(String[] args) {
        final Puhelin puhelin = new Puhelin();
        final Scanner input = new Scanner(System.in);

        System.out.println("Käytetään 1=Broadcom-kaiutinta 2=Qualcomm-kaiutinta?");
        int ans = Integer.parseInt(input.nextLine());
        if (ans == 1) {
            puhelin.setKaiutin(new BroadcomKaiutin());
        } else if (ans == 2) {
            puhelin.setKaiutin(new QualcommKaiutin());
        }
        else{
            // you re not supposed to be here. Redundant
        }

        System.out.println("Käytetään 1=Samsung-mikrofonia 2=Broadcom-mikrofonia?");
        ans = Integer.parseInt(input.nextLine());
        if (ans == 1) {
            puhelin.setMikrofoni(new SamsungMikrofoni());
        } else if (ans == 2) {
            puhelin.setMikrofoni(new BroadcomMikrofoni());
        }
        else{
            // you re not supposed to be here. Redundant
        }

        if (puhelin.getKaiutin() != null &&
                puhelin.getMikrofoni() != null) {

            do {
                System.out.println("Anna äänenvoimakkuus (0 = lopettaa ohjelman): ");
                ans = Integer.parseInt(input.nextLine());
                puhelin.getKaiutin().setVolume(ans);
                puhelin.getMikrofoni().setVolume(ans);
                System.out.println("Kaiutin: " + puhelin.getKaiutin().unMute());
                System.out.println("Mikrofoni: " + puhelin.getMikrofoni().micOn());
            } while (ans > 0);
        }

        if (input != null) {
            input.close();
        }
    }
}
