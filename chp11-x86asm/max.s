 .section .data
data_items: 		#These are the data items
 .long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

 .section .text
 .globl _start
_start:
 movl $0, %edi  	# move 0 into the index register		i = 0;
 movl data_items(,%edi,4), %eax # load the first byte of data	tmp = d[0];
 movl %eax, %ebx 	# since this is the first item, %eax is	max = tmp;
			# the biggest

start_loop: 		# start loop						
 cmpl $0, %eax  	# check to see if we've hit the end		if (tmp == 0)
 je loop_exit	#								goto loop_exit;
 incl %edi 		# load next value					i++;
 movl data_items(,%edi,4), %eax		#				tmp = d[i];
 cmpl %ebx, %eax 	# compare values					if (tmp <= max)
 jle start_loop 	# jump to loop beginning if the new			goto start_loop;
 			# one isn't bigger
 movl %eax, %ebx 	# move the value as the largest			max = tmp;
 jmp start_loop 	# jump to loop beginning				goto start_loop;

loop_exit:
 # %ebx is the status code for the _exit system call
 # and it already has the maximum number
 movl $1, %eax  	#1 is the _exit() syscall				exit(?)
			#							ebx = max;	
 int $0x80		#							exit(max);


