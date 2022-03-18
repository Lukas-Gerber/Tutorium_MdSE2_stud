# "Du wirst der allerbeste sein, wie keiner vor dir war...."

![](https://fs-prod-cdn.nintendo-europe.com/media/images/10_share_images/games_15/game_boy_4/H2x1_GB_PokemonRed_enGB_image1600w.jpg)

---
## Lesson 3:

Um die Aufgabe näher an die Hausübung heranzuführen werden wir ein wenig umstrukturieren.

__Allgemein:__

Wir werden in dieser Aufgabe Wasser-, Feuer- und Erdpokemon hinzufügen welche von einer Elternklasse Pokemon erben werden.
Weiter wird es noch eine Klasse Eispokemon geben welche von Wasserpokemon erbt.

Hier machen wir uns das Konzept der Vererbung/Generalisierung und des Polymorphismus zu nutze.

Weiters sollen entsprechende init-Funktionen als Konstruktoren umgesetzt werden.
Bei den Konstruktoren und Destruktoren sollen Textausgaben implementiert werden, um in der Konsole zu sehen, wann der Aufruf stattfindet.


__Aufgabe:__

__Attack__

Neue Klasse um verschiedene Attacken anlegen zu können.

Beinhaltet folgende Felder: name, damageType, damage, isKnown

Der Standardkonstrutor soll die Variable isKnown auf flase setzten.
Weiters ist ein Konstruktor zum initialisieren von neuen Attacken zu implementieren.

__Pokemon__

Das Pokemon erhält zusätzlich ein Array (size 4) an Attacken welche zum Angriff verwendet werden.

Weiters soll mittels folgender Funktion die Attacke zu dem Array hinzugefügt werden können

````c++
int addAttack(const Attack& attack);
````

Mittels der fight-Funktion können die Pokemon gegeneinander kämpfen.

````c++
bool fight(Pokemon *rival);
````

Mittels der getAttack-Funktion kann eine Attacke aus dem array an dem entsprechenden Index geholt werden
````c++
Attack *getAttack(int index);
````

__Wasser-, Feuer- und Erdpokemon__

Erben von der Klasse Pokemon.

Mittels dynamischer Bindung soll die attack()-Funktion von den Kindlassen überschrieben werden.

In der attack()-Funktion soll überprüft werden um welchen Gegnertypen (Feuer, Wasser, Erde) und um welche Art von Angriff es sich handelt.

z.B. soll bei einem Gegnertypen "Feuer" und einem Angriffstypen "Wasser" der Doppelte Schaden berechnet werden!

Die Pokemontypen & Schadenstypen sollen als Enum implementiert werden.

(Hier wird es Fire, Water, Earth, Ice, Normal & Flight geben!)

__Zusatzfunktionen:__

Überladen des Output-Stream operator << für alle Klassen wo es sinnvoll erscheint

# Ablauf

````
Calling waterpokemon::Constructor
Calling Firepokemon::Constructor
Calling Earthpokemon::Constructor
Calling waterpokemon::Constructor
Calling icepokemon::Constructor
------------------------------
Shiggy challenges Lavados to a fight!
Shiggy (150 hp) hits Lavados (100 hp) with tail whip for 15 damage.
Lavados (85 hp) hits Shiggy (150 hp) with heat wave for 5 damage.
Shiggy (145 hp) hits Lavados (85 hp) with rain dance for 10 damage.
Lavados (75 hp) hits Shiggy (145 hp) with heat wave for 5 damage.
Shiggy (140 hp) hits Lavados (75 hp) with rain dance for 10 damage.
Lavados (65 hp) hits Shiggy (140 hp) with heat wave for 5 damage.
Shiggy (135 hp) hits Lavados (65 hp) with hydro pump for 20 damage.
Lavados (45 hp) hits Shiggy (135 hp) with wind for 20 damage.
Shiggy (115 hp) hits Lavados (45 hp) with tail whip for 15 damage.
Lavados (30 hp) hits Shiggy (115 hp) with wind for 20 damage.
Shiggy (95 hp) hits Lavados (30 hp) with water gun for 50 damage.
Shiggy won!
Shiggy leveled up to level2 and now has 285 hitpoints.
------------------------------
... start zweiter Kampf
````