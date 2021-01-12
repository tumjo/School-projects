Potkulautojen ja sähköpotkulautojen datanhallintasovellus 

Ominaisuuksina:

1) Add a new scooter
2) Update the scooter
3) Remove the scooter
4) Search and print the scooter
5) Print scooters
6) Sort scooters by manufacturer
7) Sort scooters by serialnumber
8) Switch on/off the warnings when data changes
0) Quit

Ohjelmassa hallitaan potkulautadataa konsolisovelluksen avulla. 
Yläluokkana Scooter ja siitä periytetyt aliluokat EScooter ja KScooter. AppRun on käyttöliittymän hallinta luokka ja ScooterData final-luokka on potkulauta datan hallinta luokka. 
Käytössä on vektoritietorakenne datan halllintaan. 
Sovelluksessa hyödynnetään älykkäiden osoittimien luokkapohjaa skootteri luokkien olioihin. 
Tietueiden lajitteluun ja observer mallin toteutukseen hyödynnetääm lambda lausekkeita. 
Staattista dataa hyödynnetään tietue määrän tilastointiin. 
Gangs of Four (GoF) Design Patternista hyödynnetään sekä observeria että singletonia. 
Ohjelma on pyritty toteuttamaan modernilla C++.