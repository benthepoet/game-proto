SPRITE_SIZE= $03
SPRITE_LIST_SIZE= $08

	.org $0000
start:
	; Initialize VDP

	; Initialize array list

	.org $c000
sprites_list:
	.ds /SPRITE_LIST_SIZE SPRITES_SIZE */ ; 8 sprites at 3 bytes each
	.ds 1 ; Top of array list


