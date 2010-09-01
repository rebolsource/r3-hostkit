REBOL [
	Title: "REBOL Graphics"
	Name: graphics
	Type: extension
	Exports: [] ; added by make-host-ext.r
	; Run make-host-ext.r to convert to host-ext-graphics.h
]

init: command [
	"Initialize graphics subsystem."
	gob [gob!] "The screen gob (root gob)"
]

caret-to-offset: command [
	"Returns the xy offset (pair) for a specific string position in a graphics object."
	gob [gob!]
	element [integer! block!] "The position of the string in the richtext block"
	position [integer! string!] "The position within the string"
]

cursor: command [
	"Changes the mouse cursor image."
	image [integer! image! none!]
]

offset-to-caret: command [ ;returns pair! instead of the block..needs to be fixed
	"Returns the richtext block at the string position for an XY offset in the graphics object."
	gob [gob!]
	position [pair!]
]

show: command [
	"Display or update a graphical object or block of them."
	gob [gob! none!]
]

size-text: command [
	"Returns the size of text rendered by a graphics object."
	gob [gob!]
]

draw: command [
	"Renders draw dialect (scalable vector graphics) to an image (returned)."
	image [image! pair!] "Image or size of image"
	commands [block!] "Draw commands"
]


;#not-yet-used [
;
;effect: command [
;	"Renders effect dialect to an image (returned)."
;	image [image! pair!] "Image or size of image"
;	commands [block!] "Effect commands"
;]
;
;]