package com.company5;

public interface ITelephoneMic {
    boolean micOn();
    boolean micOff();
    void setVolume(final int volume);
    int getVolume();
}
