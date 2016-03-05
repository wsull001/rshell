test -e /home/csgrads/sgoka001/CS100/rshell/src/tests            #returns true because there exists a directory called tests
test -e /home/csgrads/sgoka001/CS100/rshell/src/Command.h        #returns true because there exists a regular file called Command.h
test -e /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp       #returns false because there is no file or directory called unreal.cpp

test -d /home/csgrads/sgoka001/CS100/rshell/src/tests            #returns true because there exists a directory called tests
test -d /home/csgrads/sgoka001/CS100/rshell/src/Command.h        #returns false because although Command.h exists, it is a regular file NOT a directory
test -d /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp       #returns false because unreal.cpp doesn't exist

test -f /home/csgrads/sgoka001/CS100/rshell/src/tests            #returns false because tests is a directory and not a regular file
test -f /home/csgrads/sgoka001/CS100/rshell/src/Command.h        #returns true because there exists a regular file called Command.h
test -f /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp       #returns false because unreal.cpp doesn't exist

test -e /home/csgrads/sgoka001/CS100/rshell/src/DIRECTORY_OR_REGULAR_FILE #works the same as the above tests for -e
test -d /home/csgrads/sgoka001/CS100/rshell/src/DIRECTORY                 #works the same as the above tests for -d
test -f /home/csgrads/sgoka001/CS100/rshell/src/REGULAR_FILE              #works the same as the above tests for -f

test -e /home/csgrads/sgoka001/CS100/rshell/src/tests && echo "path exists"        #returns true and "path exists" on the next line
test -d /home/csgrads/sgoka001/CS100/rshell/src/tests && echo "path exists"        #returns true and "path exists" on the next line
test -f /home/csgrads/sgoka001/CS100/rshell/src/Command.h && echo "path exists"    #returns true and "path exists" on the next line

test -e /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp && echo "path exists"   #returns false ONLY
test -d /home/csgrads/sgoka001/CS100/rshell/src/Command.h && echo "path exists"    #returns false ONLY
test -f /home/csgrads/sgoka001/CS100/rshell/src/tests && echo "path exists"        #returns false ONLY

[ -e /home/csgrads/sgoka001/CS100/rshell/src/tests ]            #returns true because there exists a directory called tests
[ -e /home/csgrads/sgoka001/CS100/rshell/src/Command.h ]        #returns true because there exists a regular file called Command.h
[ -e /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp ]       #returns false because there is no file or directory called unreal.cpp

[ -d /home/csgrads/sgoka001/CS100/rshell/src/tests ]            #returns true because there exists a directory called tests
[ -d /home/csgrads/sgoka001/CS100/rshell/src/Command.h ]        #returns false because although Command.h exists, it is a regular file NOT a directory
[ -d /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp ]       #returns false because unreal.cpp doesn't exist

[ -f /home/csgrads/sgoka001/CS100/rshell/src/tests ]            #returns false because tests is a directory and not a regular file
[ -f /home/csgrads/sgoka001/CS100/rshell/src/Command.h ]        #returns true because there exists a regular file called Command.h
[ -f /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp ]       #returns false because unreal.cpp doesn't exist

[ -e /home/csgrads/sgoka001/CS100/rshell/src/DIRECTORY_OR_REGULAR_FILE ] #works the same as the above tests for -e
[ -d /home/csgrads/sgoka001/CS100/rshell/src/DIRECTORY ]                 #works the same as the above tests for -d
[ -f /home/csgrads/sgoka001/CS100/rshell/src/REGULAR_FILE ]              #works the same as the above tests for -f

[ -e /home/csgrads/sgoka001/CS100/rshell/src/tests && echo "path exists" ]        #returns true and "path exists" on the next line
[ -d /home/csgrads/sgoka001/CS100/rshell/src/tests && echo "path exists" ]        #returns true and "path exists" on the next line
[ -f /home/csgrads/sgoka001/CS100/rshell/src/Command.h && echo "path exists" ]    #returns true and "path exists" on the next line

[ -e /home/csgrads/sgoka001/CS100/rshell/src/unreal.cpp && echo "path exists" ]   #returns false ONLY
[ -d /home/csgrads/sgoka001/CS100/rshell/src/Command.h && echo "path exists" ]    #returns false ONLY
[ -f /home/csgrads/sgoka001/CS100/rshell/src/tests && echo "path exists" ]        #returns false ONLY
