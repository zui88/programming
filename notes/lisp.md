# Lisp Overview

## Symbolic Expression

- *quote*

  ```lisp
  (quote (cons foo bar)) <=> '(cons foo bar)
  ```
  for denoting (adress)

## Listen

- *car*

  gibt erstes Element einer Verkettung aus

- *cdr*

  gibt zweites Element einer Verkettung aus

- *cons*

  Abkürzung für *cons*

  ```lisp
  '(x . y) <=> (cons 'x 'y)
  ```

- Liste *cons*

  ```lisp
  (cons 'x (cons 'y (cons 'z nil)))
  ```

  lange Schreibweise für Liste

- *list*

  ```lisp
  (list 'x 'y 'z)
  ```

  Abkürzung für obere Schreibweise

## Variablen Definition

First: variables have to be bound befor assignment but not necesserily. It can be bound in defenition

- *defvar*

  Assignment überschreibt Wert nur innerhalb von Block, falls zuvor festgelegt

- *defparameter*

  Gleichzeitiges Assignment überschreibt Wert, fall zuvor festgelegt

## Assignment / Binding

- *set*

  ```lisp
  (set 'foo 42)
  ```
  
- *setq*

  ```lisp
  (setq foo 42)
  ```

## Makros

- and

- or

- member

  stellt fest, ob ein Element in einer Liste enthalten ist. Zu beachten ist: *member* gibt im Erfolgsfall einfach die Suffix-Liste beginnend mit dem gefundenen Element zurück.

- append

  hängt mehrere Listen zu einer neuen zusammen

- reverse

  kehrt eine Liste um

- eq, equal und equalp

  prüft die *Identität* zweier Objekte und antwortet mit *t* oder *nil*

  gleiche Listen sind im allg. nicht identisch zueinander

  ```lisp
  (eq '(ei) '(ei))
  ```

  *NIL*

- print

- dotimes

  wie for-Schleife mit Zählvariable

  ```lisp
  (dotimes (i 6)
  	   (print (list i (* i i))))
  ```

- dolist

  wie *dotemes*; durchläuft einen Anweisungsblock für jedes Element einer Liste

  ```lisp
  (dolist (a '(11 12 13 14))
  	  (print (list a (* a a))))
  ```

### Self defined Functions

- defun

  definiert Funktionen

  ```lisp
  (defun plus1 (x) (+ x 1))
  ```


# Meta Programmierung

Bedeutungen:^[wiki: meta-]

(1) vorangestelltes Wortbildungelement, das eine Zwischenstufe oder einen Wechsel betont
(2) vorangestelltes Wortbildungelement, das in einer Hierarchie eine darüberliegende Ebene bezeichnet

Kontext Programmierung:

Darunter versteht man, dass Makro-Code vor dem Compalieren in eine für den Kompiler verständliche Syntax (Code) umgewandelt wird.
