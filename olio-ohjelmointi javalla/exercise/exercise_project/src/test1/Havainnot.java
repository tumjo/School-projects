package test1;

import java.util.List;

public class Havainnot {
    private String järjestelmänimi;
    private List<Havainto> riistahavainnot;

    public Havainnot(String järjestelmänimi, List<Havainto> riistahavainnot) {
        this.järjestelmänimi = järjestelmänimi;
        this.riistahavainnot = riistahavainnot;
    }
}
