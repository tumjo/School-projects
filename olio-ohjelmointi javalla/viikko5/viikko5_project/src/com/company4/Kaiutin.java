package com.company4;

public class Kaiutin implements ITelephoneSpeaker {

    private int volume;

    @Override
    public boolean mute() {
        return false;
    }

    @Override
    public boolean unMute() {
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
