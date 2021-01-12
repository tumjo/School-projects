package com.company;

public class Solution1 {

    public static void main(String[] args) {
    	// Maija tallettaa säästötilille ja Kalle supersaastotilille

		Saastotili saast=new Saastotili("FI49 5000 9420 0287 30", "Maiju Matikainen", 500, 4.5 );
		// TAI
		// Tili saast=new Saastotili("FI49 5000 9420 0287 30", "Maiju Matikainen", 500, 4.5 );

		SuperSaastoTili superSaast=new SuperSaastoTili("FI49 5000 9420 0487 40", "Kalle Matikainen", 500, 4.5);
		// TAI
		// Tili superSaast=new SuperSaastoTili("FI49 5000 9420 0487 40", "Kalle Matikainen", 500, 4.5);

		saast.tulostaTilinTiedot();
		superSaast.tulostaTilinTiedot();
		System.out.println("Muutetaan Maijan ja Kallen saldot 12000 € ja tulostetaan tilin tiedot...");
		superSaast.setSaldoEuroa(12000);
		saast.setSaldoEuroa(12000);
		saast.tulostaTilinTiedot();
		superSaast.tulostaTilinTiedot();

    }
}
