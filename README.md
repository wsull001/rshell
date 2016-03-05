**NAMES**: 
    Srisri Gokanapudy 861165241
    Wyatt Sullivan 861177409
<br />
**SUMMARY OF PROJECT**: The terminal is opened in the format of loginID@hostMachine$. 
                        When a command is entered the CmdFramer class reads in each 
                        command till the end of the line. Then executes it. The terminal can 
                        additionally handle test -e, -f, -d flags and outputs (true) or (false) 
                        for the tests. The terminal is now also capable of parsing precedence 
                        modifying operators (i.e parentheses) and correctly framing commands
                        modified with parentheticals.
<br />
**BUG**: When you paste text with one or more line break, our program lets you paste
        all of it before executing the commands or displaying the prompts, and then
        afterwards runs the first command and then outputs the prompts. Basically
        our terminal can't accept a copy-paste command that has multiple lines
<br />
<br />
