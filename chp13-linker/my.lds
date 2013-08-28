/* My simplest lds file */
ENTRY(add)
SECTIONS
{
  . = 0x0;
  .text           :
  {
    add.o	(.text)
    main.o	(.text)
  } 
  .data           : { *(.data) }
  .bss            :{   *(.bss)  }
}

