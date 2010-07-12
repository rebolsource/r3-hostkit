REBOL [
	Title: "REBOL Draw Graphics"
	Name: draw
	Type: extension
	Exports: none
	; Run make-host-ext.r to convert
]

words: [
	radial
	conic
	diamond
	linear
	diagonal
	cubic
]

box: command [
	"Draw a rectangular box."
	origin [pair!] "Corner of box"
	size [pair!] "Size of box"
]

lines: command [
	"Draw lines from a number of points."
	lines [block!] "Block of pairs"
]

circle: command [
	"Draw a circle or ellipse."
	origin [pair!]
	radius-x [decimal!]
	radius-y [decimal!]
]

pen: command [
	"Set the line pen color."
	color [tuple!]
]

fill-pen: command [
	"Set the area fill pen color."
	color [tuple!]
]
