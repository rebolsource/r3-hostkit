REBOL [Title: "Host-Kit Graphics: Basic GOB Compositing Test"]

view/no-wait main: make gob! [color: black offset: 0x0 size: 500x500]
;do
[
	append main make gob! [
		offset: 0x0
		size: 500x500 
		draw: [pen 255.0.0 circle 200x200 200.0 200.0]
	]
	show main
	wait 100
]

to-draw: func [block] [bind reduce block import 'draw]

units: 32
pause: .01

points: []
loop 100 [
	clear main
	clear points
	repeat n units [append points random main/size]
	append main make gob! reduce/no-set [
		offset: 0x0
		size: main/size
		draw: to-draw ['pen random 255.255.255 'lines points]
	]
	show main
	wait pause
]

loop 100 [
	clear main
	repeat n units [
		sz: random 100x100
		append main make gob! reduce/no-set [
			draw:   to-draw [
				'pen random 255.255.255 
				'fill-pen random 255.255.255.255
				'circle sz sz/x * 98% sz/y * 98%
			]
			offset: random 300x300
			size:   sz * 2
		]
	]
	show main
	wait pause
]

loop 100 [
	clear main
	repeat n units [
		sz: random 100x100
		append main make gob! reduce/no-set [
			draw:   to-draw [
				'pen random 255.255.255 
				'fill-pen random 255.255.255.255
				'box 2x2 sz
			]
			offset: random 400x400
			size:   sz + 4x4
		]
	]
	show main
	wait pause
]

loop 100 [
	clear main
	repeat n units * 10 [
		append main make gob! reduce/no-set [
			color:  random 255.255.255.255
			offset: random 500x500
			size:   random 80x80
		]
	]
	show main
	wait pause
]
