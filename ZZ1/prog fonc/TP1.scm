;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname TP1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
; Your code here!

(define last (lambda (L)
    (if (null? (cdr L))
        (car L)
        (last (cdr L)))))

(display (last '(1 1 2 3 5 8 13)))
(newline)

(define (ins_last liste elem)
  (cond             
    ((null? liste) (list elem))                  ; Sécurité : index trop grand, on met à la fin
    (else (cons (car liste)                      ; On garde le premier élément
                (ins_last (cdr liste) elem))))) ; Récursion sur le reste
            
(display (ins_last  '(3 1 2 2 1) 5))
(newline)


(define (inserer-at liste elem index)
  (cond
    ((= index 0) (cons elem liste))               ; Cas de base : on insère ici
    ((null? liste) (list elem))                  ; Sécurité : index trop grand, on met à la fin
    (else (cons (car liste)                      ; On garde le premier élément
                (inserer-at (cdr liste) elem (- index 1))))))

(display (inserer-at  '(3 1 2 2 1) 5 3))
(newline)


(define (my-reverse lst)
  (if (null? lst)
      '()
      (append (my-reverse (cdr lst))
              (list (car lst)))))
          
(display (my-reverse '(1 2 3 4 5 6)))
(newline)

(define (membre x L)
    (cond
        ((null? L) #f)
        ((equal? x (car L)) #t)
        (else (membre x (cdr L)))
                 ))
             
(display (membre 5 '(1 2 3 4)))
(newline)

(define (epure L)
    (let nettoyer ((Liste L) (vu '()))
         (cond
             ((null? Liste) '())
             ((member (car Liste) vu) (nettoyer (cdr Liste) vu))
             (else (cons (car Liste) (nettoyer (cdr Liste) (cons (car Liste) vu)))))))
(display (epure '(1 1 2 4 1 2 2 3 1 2 3)))
(newline)



(define (union L1 L2)
    (let combiner ((Liste1 L1) (Liste2 L2) (vu '()))
         (cond
             ((and (null? Liste1) (null? Liste2)) '())
             ((null? Liste1)
              (cond
                ((member (car Liste2) vu) (combiner Liste1 (cdr Liste2) vu))
                (else
                 (cons (car Liste2) (combiner Liste1 (cdr Liste2) (cons (car Liste2) vu)))))
              )
             ((member (car Liste1) vu) (combiner (cdr Liste1) Liste2 vu))
             (else
                (cons (car Liste1) (combiner (cdr Liste1) Liste2 (cons (car Liste1) vu))))))
             )
(display(union '(1 2 3 5 7 9 10) '( 2 4 6 8 10 )))
(newline)


(define (inter L1 L2)
    (let fusionner ((Liste1 L1) (Liste2 L2) (vu '()))
         (cond
           ((null? Liste1) '())
           ((member (car Liste1) vu) (fusionner (cdr Liste1) Liste2 vu))
           ((member (car Liste1) Liste2)
            (cons (car Liste1) (fusionner (cdr Liste1) Liste2 (cons (car Liste1) vu)))
           )
           (else (fusionner (cdr Liste1) Liste2 vu)))
             )
             )
(display(inter '(1 2 3 5 7 9 10) '( 2 4 6 8 10 9 )))
(newline)


(define (nieme L n) 
  (cond
    ((equal? n 1) (car L))
    ((null? L) "Liste trop petite")
    (else (nieme (cdr L) (- n 1)))))
(display (nieme '(8 7 6 5 4 3 2 1 0) 6))
(newline)



(define (flatten-deep lst)
  (cond ((null? lst) '())
        ((cons? lst) (append (flatten-deep (car lst)) (flatten-deep (cdr lst))))
        (else (list lst))))
(display (flatten-deep '(1 2 (3 4) (5 6 7 (8 9 10)))))
         (newline)


(define zip (lambda (L1 L2)
    (let fusion ((Liste1 L1) (Liste2 L2))
           (if (or (null? Liste1) (null? Liste2))
               '()
           (cons (list (car Liste1) (car Liste2)) (fusion (cdr Liste1) (cdr Liste2) )))
             )
             ))
(display(zip '(1 2 3 4 5 6) '("a" "b" "c" "d")))
(newline)


(define (prod-lst L1)
  (cond ((null? L1) 0)
        ((number? (car L1)) (+ (car L1) (prod-lst (cdr L1))))
        (else (prod-lst (cdr L1)))))
(display(prod-lst '("a" #t "deeznuts")))
(newline)


(define (fibo n)
  (if (or (equal? n 0) (equal? n 1)) 1
    (let suite-fibo ((acc n) (a 1) (b 1))
      (if (equal? acc 1)
          b
          (suite-fibo (- acc 1) b (+ a b)))
         
             )))
(display (fibo 6))
(newline)


(define (moy L)
  (let moyenne ((Liste L) (acc 0) (somme 0))
    (if (null? Liste) (/ somme (* acc 1.0))
        (moyenne (cdr Liste) (+ acc 1) (+ somme (car Liste)))
  )))
  
(display (moy '(1 2 3 4 5 6)))
(newline)
