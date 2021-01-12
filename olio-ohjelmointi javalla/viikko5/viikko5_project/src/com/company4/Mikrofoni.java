package com.company4;

public class Mikrofoni implements ITelephoneMic {
    private int volume;

    @Override
    public boolean micOn() {
        return false;
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
