
Title Project :- Implement the head command

Name :-  Kumar Mahadayya Swami

MIS NO:-  141603013

Description :-
	In this project the options like -n, -c, -q, -v,options are done. 
In Linux system, we have some alternatives about how to display a content of text files. We can use cat command, more command or less command. Another command to do it is head command.

We already know that head by default will print the first 10 lines. But we can override this setting using -n option followed by the number of line. For example, if we want to display the first 5 lines, then the command will be like this :

    $ ./project -n 5 file.txt

-v option you may need this information of the header of a file named file.txt

    $ ./project -v file.txt	
	
-c option Output the first K bytes; alternatively, use "-c +K" to output bytes starting with the Kth byte of each file.	

    $ ./project -c 4 file.txt
    	
The --help option will display the uses, synopsis and the examples for how to use the specified options for execution of the command.
After using the syntax specified in --help file it gives appropriate output.
