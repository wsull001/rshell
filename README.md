**SUMMARY OF PROJECT**: The terminal is opened in the format of loginID@hostMachine$. 
                        When a command is entered the CmdFramer class reads in each 
                        command till the end of the line. Then executes it. 
    
    
**BUG**: When you paste text with one or more line break, our program lets you paste
        all of it before executing the commands or displaying the prompts, and then
        afterwards runs the first command and then outputs the prompts. Basically
        our terminal can't accept a copy-paste command that has multiple lines
**COMPLICATION**: The assignment specs were not specific with order of operations with regards
        to linkers, so we assigned equal precedance to all of them (;, ||, and &&)