package snippet;

import javax.swing.*;
import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        double [] taulu = new double[10];
        System.out.println(taulu[2]);
        System.out.println(taulu.length);
        for(int i=0;i<taulu.length;i++){
            taulu[i]=i+100.6;
        }
        for(int i=0; i<taulu.length; i++){
            System.out.println(taulu[i]);
        }


        //ArrayList kokeilu
        ArrayList<String> nimet= new ArrayList<>();
        nimet.add("maati");
        nimet.add("Jouko");
        System.out.println(nimet.size());
        for (String nimi:nimet
             ) {
            System.out.println(nimi);

        }

        int pisteet;
        String input;
        input= JOptionPane.showInputDialog("Anna pisteet"+ "Kerron arvosanan");
        pisteet=Integer.parseInt(input);


    }


}
