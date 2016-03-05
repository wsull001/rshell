ls -cjoanvajoajnwdi && echo hello || echo world #echoes just world because it skips the hello
ls -cjoajsdofnvajfp && (echo hello || echo world) #echoes nothing
() # empty parentheses, should just do nothing
(&&) #parentheses with a connector, should do nothing
ls -a && (ls -jaoncijadfjop && echo hello || echo world) #should execute parentheses, does ls -a then echoes world, skipping hello
ls -a && (ls -joaisdfjoijan && (echo hello || echo world)) #nested parentheses test, does ls -a and then just errors on second ls

ls -a || echo hello && echo world #testing that parentheses work with the failure case
ls -a || (echo hello && echo world) #same as prev

ls -a || (echo "hello my name is" && echo "Wyatt"); echo "this should print, but the rest should not" #test that connectors work properly after parentheses commands

ls -a || (echo "hello my name is" && echo "Wyatt") && echo "this should print, but the rest should not"


