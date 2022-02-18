# "Du wirst der allerbeste sein, wie keiner vor dir war...."

Um unserer Linie aus LoBe treu zu bleiben werden wir in diesem Tutorium ein kleines Pokemon Abenteuer programmieren.
Starten werden wir mit den Kenntnissen aus C. Fortgesetzt wird dann mittels Objekt Orientierter Programmierung ab der nächsten Lesson.

Und los gehts :)

![](https://fs-prod-cdn.nintendo-europe.com/media/images/10_share_images/games_15/game_boy_4/H2x1_GB_PokemonBlue_enGB_image1600w.jpg)

---
## Lesson 1:

Doktor Eich gibt euch als **TRAINER** drei **POKEMON** zur Auswahl, aus denen ihr eines wählen dürft.
Die anderen gehen an eure RivalInnen.

__Trainer:__
name, level, storage (für Pokemon)

__Rival:__
name, level, storage (für Pokemon)

__Pokemon:__
name, hitpoints, level, pokedexnumber, isCaught


Damit wir die allerbesten werden könnne müssen wir folgende Methoden implementieren.

### Trainer:

````c++
initTrainer(Trainer_t* trainer, char* name, int level)
````
Weist einem Trainer einen Namen und ein Level zu. Initialisiert den Rucksack auf 8 Plätze.

---
````c++
fight(Trainer_t* trainer, int trainerIndex, Rival_t* rival, int rivalIndex)
````
Lässt zwei Trainer gegeneinander kämpfen.
Durch den übergebenen Index kann das Pokemon im Inventar gewählt werden.

---
````c++
showStorage(Trainer_t* trainer)
````
Durch diese Funktion erhalten wir alle Pokemon im Rucksack inkl. entsprechendem Index

---

### Rivale:
````c++
initRival(Rival_t* rival, char* name, int level)
````
---
Weist einem gegnerischen Trainer einen Namen und ein Level zu. Initialisiert den Rucksack auf 8 Plätze.

Hier haben wir im Moment noch keine weiteren Methoden, da alles über den Trainer abgewickelt wird.


### Pokemon:
````c++
initPokemon(Pokemon_t* pokemon, char* name, int level, int hitpoints, int pokedexNumber)
````
Weist einem Pokemon einen Namen, ein Level, Hitpoints und die Pokedexnummer zu.
Das Attribut isChaught wird auf true gesetzt.

---
````c++
initPokemon(Pokemon_t* pokemon)
````
Setzt isChaught auf false

---
````c++
attack(Pokemon_t* Pokemon, Pokemon_t* enemy)
````
Der Funktion werden zwei Pokemon (von je einem Trainer) übergeben.
Eines der übergebene Pokemon führt eine Attacke aus, dann werden die Seiten gewechselt.

---
````c++
void levelUp(Pokemon_t* pokemon);
````
Der Funktion wird ein Pokemon übergeben welches raufleveln soll.
Weiters werden die Lebenspunkte entsprechen angepasst (aktuelle LP + (aktuelle LP *2 ))

# Ablauf

Initialisieren des Trainers und der Rivalen.

Initialisieren der Pokemon und übergeben an die Trainer.

Anzeigen eures Rucksacks.

Über std::cin wählen welches Pokemon wir zum Kampf entsenden.

Mittels der Methode fight() wird der Kampf gestartet und läuft automatisch ab bis eine Seite verloren hat.

Das aktuelle pokemon soll raufleveln.

Dann startet ein zweiter Kampf.

Das sieht wie folgt aus:

````
-------------------
You have the following pokemon to choose from: 
0 - Shiggy   hp: 50
1 - Rettan   hp: 10
-------------------
Choose your fighter (index): 0
Ash callenges Gary to a fight!
Ash chooses Shiggy
Gary chooses Glumanda
Shiggy hits Glumanda for 1
Glumanda hits Shiggy for 5
Shiggy hits Glumanda for 4
Glumanda hits Shiggy for 1
Shiggy hits Glumanda for 4
Glumanda hits Shiggy for 4
Shiggy hits Glumanda for 1
Glumanda hits Shiggy for 1
Shiggy hits Glumanda for 1
Glumanda hits Shiggy for 5
Shiggy hits Glumanda for 3
Glumanda hits Shiggy for 2
Shiggy hits Glumanda for 3
Glumanda hits Shiggy for 2
Shiggy hits Glumanda for 5
Glumanda hits Shiggy for 4
Shiggy hits Glumanda for 2
Glumanda hits Shiggy for 5
Shiggy hits Glumanda for 1
Glumanda hits Shiggy for 3
Shiggy hits Glumanda for 1
Glumanda hits Shiggy for 3
Shiggy hits Glumanda for 4
Glumanda has 0 hitpoints left. Shiggy still has 15. Ash wins.
Shiggy leveled up to 2 and has 45 hitpoints left.
-------------------
You have the following pokemon to choose from: 
... start zweiter Kampf
````