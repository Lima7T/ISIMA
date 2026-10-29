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



