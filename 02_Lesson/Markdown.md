# "Du wirst der allerbeste sein, wie keiner vor dir war...."

![](https://fs-prod-cdn.nintendo-europe.com/media/images/10_share_images/games_15/game_boy_4/H2x1_GB_PokemonYellow_enGB_image1600w.jpg)

---
## Lesson 2:

Wir haben letztes Mal den Prototypen für unser Pokemon-Abenteuer erstellt.
Nun geht es darum diesen auf eine objekt orientierte Programmierung abzuändern.

__Aufgabe:__

Ersetzen der structs durch C++ Klassen (kein _t angehängt)

Funktionen als Objektfunktionen umsetzen.

Ersetzen der unsicheren Konstrukte durch sichere (z.B. std::string)

Objektfunktion Deklaration/Definition und Implementierung trennen (.h/.cpp)

Sichtbarkeiten definieren

Getter und Setter implementieren

__Zusatzfunktionen:__

Um die Pokemon den Trainern/Rivalen zuweisen zu können benötigen wir nun folgende Funktion:

````c++
int addPokemon(const Pokemon& pokemon)
````
Das Übergeben Pokemon wird unserer Storage hinzugefügt und wir erhalten den Index zurück.

Um die main ein wenig aufzuräumen, verlagern wir den Input (cin) und die Anzeige der showStorage()-Funktion in eine neue gemeinsame Funktion:

````c++
void choosePokemon(int& index);
````
Der Ablauf dieser soll wie folgt aussehen:
Aufruf der showStorage()-funktion,
Wählen des Pokemon und überprüfen der Eingabe, ob der gewählte Index belegt ist.

Weiters wollen wir nun auch dem Rivalen die Möglichkeit geben sein Pokemon beim Kampf zu wählen.
Daher erhält auch dieser die choosePokemon()-Funktion.

Um Verwirrungen vorzubeugen wer gerade sein Pokemon wählen darf,
soll nun in der Ausgabe der showStorage()-Funktion der entsprechende Trainername angezeigt werden.

``
XXXXX has the following pokemon to choose from:
``

# Ablauf

Der Ablauf soll wieder wie am ersten Übungsblatt verlaufen.

````
Ash has the following pokemon to choose from: 
0 - Shiggy   hp: 50
1 - Rettan   hp: 10
-------------------
Choose your fighter (index): 0
-------------------
Gary has the following pokemon to choose from: 
0 - Glumanda   hp: 30
-------------------
Choose your fighter (index): -1
Wrong input, please try again!
Choose your fighter (index): 0
Ash callenges Gary to a fight!
Ash chooses Shiggy
Gary chooses Glumanda
Shiggy hits Glumanda for 7
Glumanda hits Shiggy for 11
Shiggy hits Glumanda for 5
Glumanda hits Shiggy for 10
Shiggy hits Glumanda for 10
Glumanda hits Shiggy for 11
Shiggy hits Glumanda for 5
Glumanda hits Shiggy for 6
Shiggy hits Glumanda for 12
Glumanda has 0 hitpoints left. Shiggy still has 12. Ash wins.
Shiggy leveled up to 2 and has 36 hitpoints left.

Process finished with exit code 0

-------------------
You have the following pokemon to choose from: 
... start zweiter Kampf
````