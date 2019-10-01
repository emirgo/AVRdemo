;
; AssemblyCountry.asm
;
; Created: 30/09/2019 16:35:08
; Author : emirg
;

.DEF count = r16

MAIN:
    clr count	// clear count -- set all bits zero
	ldi count, 10 // load 10 into count
    out DDRD, count // output count to DDRD

LOOP1:
	inc count // increment count by one until 20
	out DDRD, count // output count value to DDRD
	cpi count, 20 // compare count to 20
	brne loop2 // if count isn't zero continue loop
LOOP2:
	dec count	// decrement count which was 20
	out DDRD, count // output count value to DDRD
	cpi count, 10 // compare count to 10
	brne loop2 // as long as count isn't zero continue loop the loop

//ldi count, 10 // reset count to 10
jmp main // repeat the main loop