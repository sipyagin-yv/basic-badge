#include "hw.h"
#include "menu.h"
#include <string.h>

void menu(void)
	{
	stdio_write("\nBelegrade badge version 0.27\n");
	stdio_write("Type your choice and hit ENTER\n");
	stdio_write("1 - Hackaday BASIC\n");
	stdio_write("2 - CP/M @ Z80\n");
	stdio_write("3 - Tiny Basic @ 8080\n");
	stdio_write("4 - Play Badgetris!\n");
	stdio_write("5 - User Program\n");
	
	char sstr[3];
	unsigned char cmd_line_buff[30], cmd_line_pointer;
	cmd_line_pointer=0;
	int len, i;
	
	while (1)
		{
		unsigned char get_stat = stdio_get(sstr);
		if (get_stat!=0)
			{
			stdio_write(sstr);	
			if (sstr[0]==NEWLINE) 
				{
				cmd_line_buff[cmd_line_pointer] = 0;
				if (strcmp(cmd_line_buff,"1")==0)
					{
					init_basic();
					while (1) loop_basic();
					}
				if (strcmp(cmd_line_buff,"2")==0)
					{
					init_z80_cpm();
					while (1) loop_z80_cpm();
					}			
				if (strcmp(cmd_line_buff,"3")==0)
					{
					init_8080_basic();
					while (1) loop_8080_basic();
					}
				if (strcmp(cmd_line_buff,"4")==0)
					{
					enable_display_scanning(0); //Shut off auto-scanning of character buffer
					tetrapuzz();
					}
				if (strcmp(cmd_line_buff,"5")==0)
					{
					init_userprog();
					while (1) loop_userprog();
					}			
				}
			else
				{
				len = strlen(sstr);
				for (i=0;i<len;i++)
					{
					if (sstr[i]>=' ') cmd_line_buff[cmd_line_pointer++] = sstr[i];
					else if (sstr[i]==BACKSPACE)
						{
						if (cmd_line_pointer>0) cmd_line_buff[cmd_line_pointer--]=0;
						}
					}			
				}
			}	
		}
	}