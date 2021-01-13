;; This buffer is for text that is not saved, and for Lisp evaluation.
;; To create a file, visit it with C-x C-f and enter text in its buffer.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; lists
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; dotted list
(cons 1 5)
(1 . 5)

'(1 . 5)
(1 . 5)

(quote (1 . 5))
(1 . 5)

(cons 1 '(2 3))
(1 2 3)

;; equal
(cons 'true '(2 3))
(true 2 3)

(cons (quote true) '(2 3))
(true 2 3)


(cons 'katze (cons 2 (cons 1 '())))
(katze 2 1)

(list  5 'bar)
(5 bar)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; variables
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; global
(set 'some-list '(1 2 3))
(1 2 3)

some-list
(1 2 3)

;; same
(setq my-list '(foo bar bazz))
(foo bar bazz)

my-list
(foo bar bazz)

;; scope
(let ((a 1)
      (b 5))
  (format "a is %d and b is %d" a b))
"a is 1 and b is 5"

(let* ((a 1)
      (b (+ a 5)))
  (format "a is %d and b is %d" a b))
"a is 1 and b is 6"
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; variables
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun say-hello ()
  (message "hello!"))

(say-hello)
"hello!"

(defun square (x)
  (* x x))            

(square 5)
25

(defun distance (x1 y1 x2 y2)
  (sqrt (+ (square (- x2 x1))
	   (square (- y2 y1)))))
(message "das ist das haus vom nikolaus")
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Conditionals
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; no alternitive
(when (= (+ 2 2) 4)
  (message "passed sanity check!"))
"passed sanity check!"

(defun even-or-odds (n)
  (if (= 0 (% n 2))
      "even!"
    "odd!"))

(even-or-odds 3)
"odd!"
(even-or-odds 8)
"even!"

;; as switch-case in c
(defun pick-a-word (n)
  (cond
   ((= n 1) "bulbous")
   ((= n 2) "mouffant")
   ((= n 3) "belug")
   (t "foo")))

(pick-a-word 3)
"belug"
(pick-a-word 42)
"foo"
(pick-a-word "bar!")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Recursion
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun !(n)
  (if (= n 1)
      1
    (* n (! (- n 1)))))

(! 5)
120

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Lambda - Anonymous functions
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(lambda (x) (* x x x))

((lambda (x) (* x x x)) 5)
125

(fset 'cube (lambda (x) (* x x x)))

(cube 4)
64
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Higher-order functions
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; apply every member in the list to the function
(mapcar 'upcase '("foo" "bar" "baz"))

(mapcar 'upcase '())

(oddp 3)
(oddp 4)

;; like a filter
(remove-if-not 'oddp
	       '(0 1 2 3 4 5 6 7 8 9))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Example
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Quicksort
(defun qs (list)
  "Non-destructively sort the
elements of 'list' using quicksort."
  (if (null list)
      '()
    (let* ((pivot (car list))
	   (rest (cdr list))
	   (lesser (remove-if-not
		    (lambda (x) (<= x pivot)) rest))
	   (greater (remove-if-not
		     (lambda (x) (> x pivot)) rest)))
      (append (qs lesser) (list pivot) (qs greater)))))

(qs '(3 6 1 8 42))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Keybindings
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(global-set-key (kbd "M-#") 'sort-lines)

major-mode

;; locally bound
(add-hook 'c-mode-common-hook
	  (lambda ()
	    (local-set-key (kbd "<f5>") 'recompile)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Built-in documentation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(kbd "C-h k")

;; C-h k
(describe-key (kbd "C-h k"))

;; C-h a
(apropos-command "region")

;; C-h f
(describe-function 'qs)

;; C-h v
(describe-variable 'path-seperator)

;; C-h #
(describe-mode)

;; C-h C-h
(help-for-help)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Further informations
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; "Learn Emacs Lisp in 15 Minutes"
;; search for that string above
(browse-url
 "http://bzg.fr/learn-emacs-lisp-in-15-minutes.html")

;; The built-in "An Introduction to Programming in Emacs Lisp"
(info "(eintr) Top")

;; the built-in "Emacs Lisp Reference"
(info "(elisp) Top")


