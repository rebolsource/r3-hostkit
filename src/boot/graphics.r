REBOL [
	Title: "REBOL Graphics"
	Name: graphics
	Type: extension
	Exports: [] ; added by make-host-ext.r
	; Run make-host-ext.r to convert to host-ext-graphics.h
]

init: command [
	"Initialize graphics subsystem (needs to not be exported!)."
	gob [gob!] "The screen gob (root gob)"
]

show: command [
	"Display or update a graphical object or block of them."
	gob [gob! none!]
]

;draw: command [
;	"Renders draw dialect (scalable vector graphics) to an image (returned)."
;	image [image! pair!] "Image or size of image"
;	commands [block!] "Draw commands"
;]
;
;cursor: command [
;	"Changes the mouse cursor image."
;	image [integer! image! none!]
;]
;
;size-text: command [
;	"Returns the size of text rendered by a graphics object."
;	gob [gob!]
;]
;
;caret-to-offset: command [
;	"Returns the xy offset (pair) for a specific string position in a graphics object."
;	gob [gob!]
;	element [block! integer!] "The position of the string in the richtext block"
;	position [string! integer!] "The position within the string"
;]
;
;offset-to-caret: command [
;	"Returns the richtext block at the string position for an XY offset in the graphics object."
;	gob [gob!]
;	position [pair!]
;]
;
;#not-yet-used [
;
;effect: command [
;	"Renders effect dialect to an image (returned)."
;	image [image! pair!] "Image or size of image"
;	commands [block!] "Effect commands"
;]
;
;]