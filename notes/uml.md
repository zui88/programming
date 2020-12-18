# UML

## Paketdiagramm

__Definition__

Ein Paket wird benutzt, um Elemente zu gruppieren und einen Namensraum für seine Elemente zu liefern.

starke Bindung
:      Pakete, Klassen sind durch viele Assoziationen miteinander verknüpft.

:      liegen in einer Hierarchie

Ein Paket erstellt eine *Kapsel*. Wenn diese Kapsel von wenig Verbindungen durchbrochen wird, spricht man von einer schwachen Kopplung.

schwache Kopplung
:    Wird eine *Kapsel* durch wenige Verbindungen durchbrochen, liegt eine schwach Koplpung (Bindung) vor.

Starke Bindung und schwache Kopplung sind Entwurfsziele bei der Modularisierung.

__AbhÃ¤ngigkeiten__

Sie zeigen nicht die genaue Arten der AbhÃ¤ngigkeiten der Klassen der Pakete untereinander aus, sondern signalisieren allgemein, dass ein Paket ein anderes fÃ¼r dessen ausfÃ¼hrung benÃ¶tigt.

- Ein Paket kann selbst Pakete oder auch Klassen enthalten.

- Pakete bilden NamensrÃ¤ume, d.h. der selbe Name kann in verschiedenen Pakteten vorkommen.

Braucht ein Paket Zugriff auf die Elemente eines anderen Paketes, kann dies durch eine AbhÃ¤ngigkeit gekennzeichnet werden mit dem Stereotyp *<<import>>*. Alle Ã¶ffentliche Elemente des importierten Pakets werden greifbar. Ein Paket importiert automatisch die in ihm geschachtelten Pakete. Der Namenraum wird erweitert.

- Ein Paket sollte eine abgeschlossene Einheit sein.

