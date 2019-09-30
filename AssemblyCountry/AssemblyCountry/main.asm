;
; AssemblyCountry.asm
;
; Created: 30/09/2019 16:35:08
; Author : emirg
;

.DEF tmp = r16
.DEF count = r17

MAIN:
    clr tmp	// clear tmp -- set all bits zero
	ldi tmp, 10 // load 10 into tmp
    out DDRD, tmp // output tmp to DDRD
	ldi count, 10 // load 10 into count

	LOOP0: // main loop - forever loop
		LOOP1:
			inc tmp // increment tmp by one until 20
			out DDRD, tmp // output tmp value to DDRD
			dec count // decrement count by one
			brne loop1 // if count isn't zero continue loop

		ldi count, 10 // reset/load count to 10
		LOOP2:
			dec tmp	// decrement tmp which was 20
			out DDRD, tmp // output tmp value to DDRD
			dec count // decrement count
			brne loop2 // as long as count isn't zero continue loop the loop

		ldi count, 10 // reset count to 10
		jmp loop0 // repeat the main loop