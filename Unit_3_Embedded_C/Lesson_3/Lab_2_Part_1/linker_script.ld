/* Linker Script CortexM3
Eng.Mina Fathy
*/

MEMORY
{
flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}> flash
	
	.data :
	{
		*(.data*)
	}> flash
	
	.bss :
	{
		*(.bss*)
	}> sram
	

}