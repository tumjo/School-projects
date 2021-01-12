package com.company2;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class FileUtils {

    // ReadFromFile-metodi ottaa vastaan tiedoston nimen, josta sisältöä luetaan ja palauttaa sisällön String-muotoisena käyttäjälle.
    // Huom! Lukemista ei tässä tapauksessa tehdä taustalla.
    public static String ReadFromFile(final String nimi) throws IOException {
        Path fileName = Path.of(nimi);
        String saatuTeksti = Files.readString(fileName);
        return saatuTeksti;
    }
    // WriteToFile-metodi ottaa vastaan tiedoston nimen, johon kirjoitetaan, sekä tässä tapauksessa käyttäjän antaman String-muotoisen syötteen. Kun metodia kutsutaan se käynnistää säikeen,
    // jossa käyttäjän syöte kirjoitetaan tiedostoon taustalla. Edellinen syöte kirjoitetaan aina yli, joten ns. append-toimintoa ei tarvitse toteuttaa.
    public static void WriteToFile(final String nimi, final String teksti){
        Thread thread1=new Thread() {
            @Override
            public void run(){
                try {
                    FileWriter fileWriter = new FileWriter(nimi);
                    fileWriter.write(teksti);
                    fileWriter.close();
                } catch (IOException e) {
                    System.out.println(e.getMessage());
                    e.printStackTrace();
                }
            }
        };
        thread1.start();
        while(thread1.isAlive()){
            // Odotetaan säikeen valmistumista eli kirjoituksen valmistumista kuten tehtävänanto määrää, vaikka ehkä keinotekoisella odottamisella tätä samaa haettiin ennen seuravaa tämän luokan metodin kutsua.
        }
    }
}
