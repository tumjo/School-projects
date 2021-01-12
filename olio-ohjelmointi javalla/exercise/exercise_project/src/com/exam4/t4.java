package com.exam4;

public class t4 {
    public static void main(String[] args) {
        // Tehtävänanto EI määritellyt kuinka vuokraus tulee käsitellä "aina pakettina" jotenka luon jokaisesta aliluokasta olion, jotka pääohjelmassa kokoan osaksi vuokrapakettia.
        // Yksi mahdollisuus olisi ollut luoda kokoojaluokka joka sisältää pakettiin tulevat oliot. Sitä tehtävänanto ei kuitenkaan määrännyt.

        // Sukset esim
        Sukset sukset1=new Sukset();
        sukset1.setHinta(99.99);
        sukset1.setKayttoonottopaiva("1.6.2020");
        sukset1.setMerkki("Atomic");
        sukset1.setPituus(140);

        // Monot esim
        Monot monot1 = new Monot(30.20,"1.6.2020",42,6);

        // Sauvat esim
        Sauvat sauvat1=new Sauvat(15.99,"1.6.2020", 62.5);

        // Kypärä esim
        Kypara kypara1 = new Kypara(8.99,"1.6.2020",12,"punainen");

        System.out.println("Paketti sisältää seuraavat tuotteet...");
        System.out.println(sukset1);
        System.out.println(monot1);
        System.out.println(sauvat1);
        System.out.println(kypara1);
        System.out.println();
        System.out.println("Paketin kokonaishinnaksi tulee " + String.format("%1.2f", (sukset1.getHinta()+ monot1.getHinta()+sauvat1.getHinta()+kypara1.getHinta())) + " euroa per pv.");
    }
}
