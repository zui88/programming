;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Binary Tree

;; structure
;; (father left-subtree right-subtree)

;; car   -> father
;; cadr  -> left-subtree
;; caddr -> right-subtree

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; insert

;; T: tree, z: to-insert
(defun insert-bst (z T)
  (cond ((null T) (list z nil nil))
	;; equal
	((= z (car T)) T)
	;; lesser than
	((< z (car T))
	 ;; root doesent change as for the right sub-tree
	 ;; what changes is the left sub-tree by recursion
	 (list (car T) (insert-bst z (cadr T))
	       (caddr T)))
	;; remaining possibility -> always true
	;; greater than t: true
	(t (list (car T) (cadr T)
		 ;; right sub-tree
		 (insert-bst z (caddr T))))))

;; some tests
(insert-bst 4 '(2 nil nil))
(2 nil (4 nil nil))

(insert-bst 4 '(8 nil (6 nil nil)))
(8 (4 nil nil) (6 nil nil))

(insert-bst 8 '(4 nil nil))
(4 nil (8 nil nil))

;; more bigger tree
(setq tree '(15
	     ;; left-subtree
	     (6 (3 (2 nil nil) (4 nil nil)) (7 nil (13 (9 nil nil) nil)))
	     ;; right-subtree
	     (18 (17 nil nil) (20 nil nil))))

(setq res (insert-bst 8 tree))
res
(15 (6 (3 (2 nil nil) (4 nil nil)) (7 nil (13 (9 (8 nil nil) nil) nil))) (18 (17 nil nil) (20 nil nil)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; search

;; z: element to search for, T: tree
(defun search-bst (z T)
  (cond ((null T) nil)
	((= z (car T)) z)
	((< z (car T)) (search-bst z (cadr T)))
	(t (search-bst z (caddr T)))))

;; in list
(search-bst 6 tree)
6

(search-bst 20 tree)
20

;; not in list
(search-bst 42 tree)
nil

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; tree-minimum

(defun tree-minimum (T)
  (if (cadr T) (tree-minimum (cadr T)) (car T)))

(tree-minimum tree)
2

;; void list
(tree-minimum '())
nil

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; tree-maximum

(defun tree-maximum (T)
  (if (caddr T) (tree-maximum (caddr T)) (car T)))

(tree-maximum tree)
20

;; void list
(tree-maximum '())
nil

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; successor - Nachfolger

;; keine Schluesselvergleiche notwendig - gesammte Information steckt
;; in Strucktur des Baumes bzw. des uebergebenen Knotens

;; minimal key -> nearest key
;; y.key > z.key

;; helper function - skeleton
;; check if list part of another list -> if subtree (child) is part of the tree (father)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Misc

(if nil 'a 'b)
b

(if nil 'a)
nil

(< 1 2)
t
(< 4 2)
nil

(null nil)
t

(set 'a 42)
42

(null a)
nil

(null (list 'b 'c 'd))
nil

(null '())
t


;;;;;;;;;;;;;;;;;;;;;;;;;
;; Another tree implementation

(defun make-tree (item)
"Creates a new node that contains 'data' as its data."
  (cons (cons item nil) nil))

(make-tree 5)
((5))

(defun add-child (tree child)
  "Takes two nodes created with 'make-tree' and adds the second
node as a child of the first. Returns the first node, which will
be modified.

Notice: the function will modifiy the node passed as the first
argument, it is a destructive function, it has side effects."
  (setf (car tree) (append (car tree) child))
  tree)

(append (car '((5) (4))) '((1)))
(5 (1))

(car '(((1) (3))))
((1) (3))

(car '((1) (3)))
(1)

(append '(1) '(2 3))
(1 2 3)

(add-child (make-tree "root") (make-tree "first-child"))
(("root" ("first-child")))

(defun first-child (tree)
  "Returns a reference to the first child of the node passed in,
  or nil if this node does not have children."
  (cdar tree))

(defun next-sibling (tree)
  "Returns a reference to the next sibling of the node passed in,
or nil if this node does not have any siblings."
  (cdr tree))

(defun data (tree)
  "Returns the information contained in this node."
  (caar tree))

(let ((one (make-tree 1)))
  (add-child one (make-tree 2))
  (add-child one (make-tree 4))
  (add-child one (make-tree 5))
  (let ((two (first-child one)))
    (add-child two (make-tree 6))
    (add-child two (make-tree 7))
    (let ((four (next-sibling two)))
      (add-child four (make-tree 9))
      (add-child (first-child four) (make-tree 12))))
  one)
((1 (2 (6) (7)) (4 (9 (12))) (5)))
