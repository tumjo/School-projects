package com.company4;

public class Solution3 {
    public static void main(String[] args) {
        // Test
        Kaiutin ka=new Kaiutin();
        Mikrofoni mik=new Mikrofoni();
        ka.setVolume(1);
        System.out.println(ka.getVolume());
        mik.setVolume(100);
        System.out.println(mik.getVolume());
        System.out.println(mik.micOn());
    }
}
