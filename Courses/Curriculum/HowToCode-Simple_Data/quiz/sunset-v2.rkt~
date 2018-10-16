;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname sunset-v2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)

; ==========
; Constants

(define WIDTH 600)
(define HEIGHT 400)
(define MTS (empty-scene WIDTH HEIGHT))

(define LAND (rectangle (+ WIDTH 200) (/ HEIGHT 3)
                        "solid" "brown"))

(define MOUNTAINS (beside (triangle 270 "solid" "brown")
                          (triangle 230 "solid" "brown")
                          (triangle 250 "solid" "brown")
                          (triangle 290 "solid" "brown")))

(define SCENERY (overlay MOUNTAINS LAND))

(define BACKGROUND (place-image MOUNTAINS       ;; places the scenery on the empty MTS background
                                (/ WIDTH 2)
                                (* (/ HEIGHT 3) 2)
                                (place-image SCENERY
                                             (+ (/ WIDTH 2) 70)
                                             (+ (* (/ HEIGHT 4) 2) 133)
                                              MTS)))

(define SUN (overlay (circle 30 "solid" "yellow") 
            (radial-star 32 30 40 "solid" "orange")))
(define SUN-CTR-X (/ WIDTH 2))
(define X-MAX (+ WIDTH 100))
(define START-X -100)
(define START-Y 250)

;; ==============
;; Data Definitions

(define-struct sun (x dx y dy))
;; Sun is (make-sun Natural[[START, X-MAX], [250, HEIGHT)] Integer)
;; interp. (make-sun x dx y dy is a sun with x coordinate, x velocity, y coordinate and y velocity
;;                   x is the center of a sun
;;                   x and y are in screen coordinates (pixels)
;;                   dx and dy are in pixels per tick

(define S1 (make-sun 0 2 (/ HEIGHT 2) 1))
(define S2 (make-sun START-X 2 START-Y 1)) ; start point of the sun

#;
(define (fn-for-sun s)
  (... (sun-x s)
       (sun-dx s)
       (sun-y s)
       (sun-dy s)))

;; Template rules used:
;;    - compound: 4 fields


;; ================
;; Functions:

;; Sun -> Sun
;; called to have the sun rise up the scenery and go back down as reaching the edge of the scene
;; start with (main (make-sun START-X 2 START-Y 1))

;; no tests for main function
(define (main s)
  (big-bang s
            (on-tick next-sun) ; Sun -> Sun
            (to-draw render-sun) ; Sun -> Image
            (on-key handle-key))) ; Sun Key Event -> Sun


;; Sun -> Sun
;; increase Sun x,y by dx,dy;
;; sun goes up in the first half of the scene and down in the second half
;; when it reaches X-MAX, disappears and starts from initial position

(check-expect (next-sun (make-sun 50 2 (/ HEIGHT 2) 1))
              (make-sun 52 2 (- (/ HEIGHT 2) 1) 1)) ; first half of the scene, going up
(check-expect (next-sun (make-sun (+ (/ WIDTH 2) 50) 2 (- (/ HEIGHT 4) 50) -1))
              (make-sun (+ (/ WIDTH 2) 52) 2 (- (/ HEIGHT 4) 51) -1)) ; second half of the scene, going down

(check-expect (next-sun (make-sun (- SUN-CTR-X 2) 2 (/ HEIGHT 4) 1))
                        (make-sun SUN-CTR-X 2 (- (/ HEIGHT 4) 1) 1)) ; reaches center of scene

(check-expect (next-sun (make-sun (+ WIDTH 98) 2 2 1))
              (make-sun X-MAX 2 3 1)) ; reaching the far right boundary

(check-expect (next-sun (make-sun (- X-MAX 1) 2 1 1))
              (make-sun START-X 2 START-Y 1)) ; trying to pass the far right boundary, reset to initial position
              

#;
(define (next-sun s) s) ; stub
 
;; took template from sun
(define (next-sun s)
  (cond [(> (+ (sun-x s) (sun-dx s)) X-MAX)
        (make-sun START-X (sun-dx s) START-Y (sun-dy s))]
        [(> (+ (sun-x s) (sun-dx s)) SUN-CTR-X)
         (make-sun (+ (sun-x s) (sun-dx s)) (sun-dx s) (+ (sun-y s) (sun-dy s)) (sun-dy s))]
        [else
         (make-sun (+ (sun-x s) (sun-dx s)) (sun-dx s) (- (sun-y s) (sun-dy s)) (sun-dy s))]))


;; Sun -> Image
;; place sun image on the BACKGROUND at (sun-x s) and (sun-y s)

(check-expect (render-sun (make-sun 99 3 (/ HEIGHT 2) 1))
              (place-image SUN 99 (/ HEIGHT 2) BACKGROUND))

(check-expect (render-sun (make-sun 33 -3 (/ HEIGHT 2) 1))
              (place-image SUN 33 (/ HEIGHT 2) BACKGROUND))

#;
(define (render-sun s) BACKGROUND) ; stub

;; took template from sun
(define (render-sun s)
  (place-image SUN (sun-x s) (sun-y s) BACKGROUND))


;; Sun KeyEvent-> Sun
;; interp. reset the sun to its original starting point when space bar is pressed

(check-expect (handle-key (make-sun (- SUN-CTR-X 2) 2 (/ HEIGHT 4) 1) " ")
              (make-sun -100 2 250 1))

(check-expect (handle-key (make-sun (- SUN-CTR-X 2) 2 (/ HEIGHT 4) 1) "a")
              (make-sun (- SUN-CTR-X 2) 2 (/ HEIGHT 4) 1))

#;
(define (handle-key s ke) s) ;stub

;; took template from sun
(define (handle-key s ke)
  (if (key=? " " ke)
      (make-sun -100 2 250 1)
      s))

