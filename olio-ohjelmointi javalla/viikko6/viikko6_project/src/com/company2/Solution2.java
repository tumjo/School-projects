package com.company2;

import java.io.IOException;
import java.util.Scanner;

public class Solution2 {
    public static void main(String[] args) throws IOException {
        // Pääohjelma kysyy käyttäjältä tiedoston nimen, johon tietoa halutaan kirjoittaa sekä syötteen.
        // Kun käyttäjä on antanut tiedot, kirjoitetaan syöte tiedostoon käyttäen FileUtils-luokan WriteToFile-metodia.
        // Kun kirjoitus on tehty, käynnistetään pääohjelmassa uusi säie,
        // joka odottaa ensin sekunnin ja sen jälkeen tulostaa tiedoston sisällön käyttäen FileUtils-luokan ReadFromFile-methodia.
        final String nimi;
        final String teksti;
        Scanner input = new Scanner(System.in);
        System.out.print("Anna tiedoston nimi: ");
        nimi=input.nextLine();
        System.out.print("Anna syöte, joka kirjoitetaan tiedostoon: ");
        teksti=input.nextLine();
        FileUtils.WriteToFile(nimi,teksti);
        Thread thread2=new Thread() {
            @Override
            public void run(){
                try {
                    Thread.sleep(1000);
                }catch (Exception e){
                    System.out.println(e);
                }finally {
                    try {
                        System.out.println(FileUtils.ReadFromFile(nimi));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        };
        thread2.start();
    }
}
