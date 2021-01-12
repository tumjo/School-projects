package sample;

import javafx.application.Application;

import javafx.geometry.Insets;

import javafx.geometry.Pos;

import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

import javafx.scene.layout.GridPane;

import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

import javafx.stage.Stage;

public class Main extends Application {
    //Savoniassa on päätetty tehdä pilottikokeilu, jossa poistoon meneviä tietokoneita sekä tarvikkeita myydään oppilaille verkkokaupan kautta.
    // Pääset osallistumaan projektiin ja käyttämään luovaa ajattelua käyttöliittymän suunnittelussa. Tee JavaFX-kirjastoa käyttäen käyttöliittymä,
    // jossa verkkokauppaan syötetään tuote ja sen tiedot. Tuotteesta tarvittavat tiedot:
    //- Nimi
    //- Tuotetyyppi (esim. tietokone, hiiri, monitori). Tämä voisi olla alasvetovalikko.
    //- Käyttöönottopäivä. Tämä valitaan kalenterista (Date Picker).
    //- Myyntihinta
    //- Ostajan nimi
    // Tärkeää on myös, että ruudun ylälaidassa on Savonian logo. Ruudulla lisäksi on alalaidassa ”Tallenna”- ja ”Sulje”-napit, jotka eivät vielä tee mitään.”
    @Override
    public void start(Stage primaryStage) throws Exception{
        GridPane paneeli= new GridPane();
        paneeli.setAlignment(Pos.CENTER);
        paneeli.setPadding(new Insets(8,8,8,8));
        paneeli.setHgap(10);
        paneeli.setVgap(10);

        Image kuva = new Image("savonia.jpg");
        ImageView imageView=new ImageView(kuva);
        imageView.setFitHeight(25);
        imageView.setFitWidth(80);
        paneeli.add(imageView, 0, 0);

        Text otsikko = new Text("Anna tiedot");
        otsikko.setFont(Font.font("Tahoma", FontWeight.NORMAL, 20));
        paneeli.add(otsikko, 0, 0, 50, 6);
        paneeli.add(new Label("Nimi: "), 0, 5);
        paneeli.add(new TextField(), 1, 5);

        ComboBox comboBox = new ComboBox();
        comboBox.getItems().add("Tietokone");
        comboBox.getItems().add("Hiiri");
        comboBox.getItems().add("Monitori");
        paneeli.add(new Label("Tuotetyyppi: "), 0, 7);
        paneeli.add(comboBox, 1, 7);

        DatePicker datePicker = new DatePicker();
        paneeli.add(new Label("Käyttöönottopäivä: "), 0, 9);
        paneeli.add(datePicker, 1, 9);

        paneeli.add(new Label("Myyntihinta: "), 0, 11);
        paneeli.add(new TextField(), 1, 11);

        paneeli.add(new Label("Ostajan nimi: "), 0, 13);
        paneeli.add(new TextField(), 1, 13);

        paneeli.add(new Button("Tallenna"),0,40);
        paneeli.add(new Button("Sulje"),1,40);

        primaryStage.setTitle("Solution3");
        primaryStage.setScene(new Scene(paneeli, 1000, 600));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
