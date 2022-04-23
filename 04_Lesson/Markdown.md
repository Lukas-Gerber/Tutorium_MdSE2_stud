# "Du wirst der allerbeste sein, wie keiner vor dir war...."

![](https://fs-prod-cdn.nintendo-europe.com/media/images/10_share_images/games_15/game_boy_color_5/H2x1_GBC_PokemonCrystal_enGB.jpg)

---
## Lesson 4:


__Heap_Objekte:__

In dieser Aufgabe werden wir die Attacken als Heap-Objekte (new Operator) erstellen. 
Dadurch werden die Objekte in Zukunft nicht mehr als Kopie sondern als Referenz bzw. Pointer gespeichert.

Die Objektvariable storage soll als Pointer umgesetzt werden und alle Funktionen welche Attacken zurückgeben besitzen nun als Rückgabewert einen Pointer.

Eingabeargumente werden ebenfalls mittels Pointer übergeben.

Ob eine Attacke erlernt wurde oder nicht wird in Zukunft nicht mehr mittels isKnown festegestellt sondern ob ein nullpointer oder ein Attack-Objekt an dem Speicherplatz vorhanden ist.

Es ist darauf zu achten, dass keine Speicherlecks entstehen und Gegenstände welche nicht mehr gebraucht werden zuerstört werden

__Exceptions__

Die Robustheit des Programmes soll mittels Exceptions neu konzipiert werden.
z.B. sollen Funktionen bei Zugriff auf ein Array bei einem ungültigen Index eine entsprechende Exception werfen

Ist der Attack-Storage voll soll ebenfalls eine exception geworfen werden

Wird dem Konstruktor ein falsches Eingabeargument übergeben soll auch hier die entsprechende exception ausgeführt werden

Zum abfangen der exceptions soll ein entsprechender Exception-Handler eingefügt werden.


# Ablauf
Der normale Ablauf bleibt wie in der vorherigen Lesson bestehen. Bei einer exception soll diese jedoch ausgegeben werden!