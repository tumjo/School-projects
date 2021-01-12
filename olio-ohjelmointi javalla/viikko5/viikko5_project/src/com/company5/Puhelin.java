package com.company5;

public class Puhelin {
    private ITelephoneMic mikrofoni;
    private ITelephoneSpeaker kaiutin;

    public ITelephoneMic getMikrofoni() {
        return mikrofoni;
    }

    public void setMikrofoni(ITelephoneMic mikrofoni) {
        this.mikrofoni = mikrofoni;
    }

    public ITelephoneSpeaker getKaiutin() {
        return kaiutin;
    }

    public void setKaiutin(ITelephoneSpeaker kaiutin) {
        this.kaiutin = kaiutin;
    }
}
