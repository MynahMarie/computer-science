;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname isLarger) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

;; IMAGE IMAGE -> Boolean    ;signature
;; produce true if the first image is larger then the second   ;purpose

(define IMG1 (square 20 "solid" "black"))
(define IMG2 (triangle 30 "outline" "green"))

(check-expect (isLarger? IMG1 IMG2) false)
(check-expect (isLarger? IMG2 IMG1) true)
(check-expect (isLarger? IMG1 IMG1) false)

;; (define (isLarger? img1 img2) false)    ;stub

;; (define (isLarger? img1 img2)   ;template
;;   (... img1 img2)

(define (isLarger? IMG1 IMG2)
  (> (image-width IMG1) (image-width IMG2)))
