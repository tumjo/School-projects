package com.company4;

public interface ITelephoneSpeaker {
    boolean mute();
    boolean unMute();
    void setVolume(final int volume);
    int getVolume();
}
