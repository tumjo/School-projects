package com.company5;

public class QualcommKaiutin implements ITelephoneSpeaker{
    private int volume;

    @Override
    public boolean mute() {
        return false;
    }

    @Override
    public boolean unMute() {
        return volume<=80;
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
