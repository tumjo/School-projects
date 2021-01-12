package com.company;

public class PrintDiamond implements Runnable {

    public void print() {
        int osat=5;
        for (int i = 1; i <= osat; i++) {
            for (int j = osat; j >= i; j--) {
                System.out.print(" ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
            // test
            /*
            try {
                Thread.sleep(1000);
            }catch (Exception e){
                System.out.println(e);
            }
            */
        }
        for (int i = 1; i <= osat-1; i++) {
            for (int j = 1; j <= i+1; j++) {
                System.out.print(" ");
            }
            for (int j = i; j <= osat-1; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    @Override
    public void run() {
        this.print();
    }
}
