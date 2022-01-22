;; chicken.scm - Example usage of bindings for CHICKEN 5.
;; Copyright (C) 2022 Robert Coffey

(import (srfi 18) ; thread-sleep!
        prog-bar)

;; Progress bar using the low level bindings.
(let ((pb (make-prog-bar 8 8)))
  (prog-bar-draw pb)
  (flush-output)
  (thread-sleep! (/ 1 5))
  (do ((i 0 (+ i 1)))
      ((= i 8))
    (display #\return)
    (prog-bar-step! pb)
    (prog-bar-draw pb)
    (flush-output)
    (thread-sleep! (/ 1 5)))
  (destroy-prog-bar pb))
(newline)

;; Progress bar using the high level macro.
(with-prog-bar pb 8 8
  (prog-bar-draw pb)
  (flush-output)
  (thread-sleep! (/ 1 5))
  (do ((i 0 (+ i 1)))
      ((= i 8))
    (display #\return)
    (prog-bar-step! pb)
    (prog-bar-draw pb)
    (flush-output)
    (thread-sleep! (/ 1 5))))
(newline)
