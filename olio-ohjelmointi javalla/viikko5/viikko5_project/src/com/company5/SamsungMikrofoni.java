package com.company5;

public class SamsungMikrofoni implements ITelephoneMic {
    private int volume;

    @Override
    public boolean micOn() {
        return volume<=60;
    }

    @Override
    public boolean micOff() {
        return false;
    }

    @Override
    public void setVolume(int volume) {
        this.volume=volume;
    }

    @Override
    public int getVolume() {
        return volume;
    }
}
