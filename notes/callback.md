# Rückruffunktion[^1]	(Callback)

ist eine Funktion, die einer andere Funktion^[meist einer Bibliotheksfunktion] als Parameter übergeben wird.

![Einfacher Callback](CallbackSimple.png)

In der Abbildung wird die Rückruffunktion einer Routine (grünes Feld) übergeben. Die aufgerufene Routine entscheidet darüber, wann sie die Rückruffunktion aufrufen wird. Das wird *Inversion of Controll* genannt.

**Merkmal:** Nicht der Aufrufer (aquamarinfarbenes Feld) steuert die Ausführung, sondern die aufgerufene Routine (grünes Feld).

Die Rückruffunktion legt letztendlich Daten ab, die nach der Rückkehr des ursprünglichen Aufrufers verwendet werden können.

Vorteile sind:

- Der Zugriff auf die Daten wird im eigenen Kontext formuliert und im Rückruf kann eine programmtechnische Aufbereitung erfolgen. Die Parameter und der Aufrufzeitpunkt werden im anderen Softwaremodul bestimmt (grües Feld). Die Bestimmung, was im Rückruf ausgeführt wird, obliegt dem eigenen Softwaremodul.

- Funktionen können somit allgemeiner definiert werden und erst beim Aufruf der Funktion durch Angabe der Rückruffunktion wird das Verhalten exakt bestimmt.

<!-- ------------------------------------------------------- -->

[^1]: [Wikipedia Rückruffunktion][wiki_callback]

[wiki_callback]: https://de.wikipedia.org/wiki/R%C3%BCckruffunktion#:~:text=Eine%20R%C3%BCckruffunktion%20(englisch%20callback%20function,mit%20definierten%20Argumenten%20aufgerufen%20wird
