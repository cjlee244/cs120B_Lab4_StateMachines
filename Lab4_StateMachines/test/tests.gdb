# Test file for "Lab4_StateMachines"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "Initial State"
setPINA 0x00
continue 2
expectPORTC 0x07
checkResult

test "7 + 1"
setPINA 0x01
continue 2
expectPORTC 0x08
checkResult

test "8 + 1"
setPINA 0x01
continue 2
expectPORTC 0x09
checkResult

test "9 + 1 (Over Max)"
setPINA 0x01
continue 2
expectPORTC 0x09
checkResult

test "9 - 1"
setPINA 0x02
continue 2
expectPORTC 0x08
checkResult

test "8 - 1"
setPINA 0x02
continue 2
expectPORTC 0x07
checkResult

test "7 - 1"
setPINA 0x02
continue 2
expectPORTC 0x06
checkResult

test "6 - 1"
setPINA 0x02
continue 2
expectPORTC 0x05
checkResult

test "5 - 1"
setPINA 0x02
continue 2
expectPORTC 0x04
checkResult

test "4 - 1"
setPINA 0x02
continue 2
expectPORTC 0x03
checkResult

test "3 - 1"
setPINA 0x02
continue 2
expectPORTC 0x02
checkResult

test "2 - 1"
setPINA 0x02
continue 2
expectPORTC 0x01
checkResult

test "1 - 1"
setPINA 0x02
continue 2
expectPORTC 0x00
checkResult

test "0 - 1 (Under Max)"
setPINA 0x02
continue 2
expectPORTC 0x00
checkResult

test "0 + 1"
setPINA 0x01
continue 2
expectPORTC 0x01
checkResult

test "1 + 1"
setPINA 0x01
continue 2
expectPORTC 0x02
checkResult

test "2 + 1"
setPINA 0x01
continue 2
expectPORTC 0x03
checkResult

test "3 + 1"
setPINA 0x01
continue 2
expectPORTC 0x04
checkResult

test "4 + 1"
setPINA 0x01
continue 2
expectPORTC 0x05
checkResult

test "5 + 1"
setPINA 0x01
continue 2
expectPORTC 0x06
checkResult

# both pressed simultaneously
test "Reset 0"
setPINA 0x03
continue 2
expectPORTC 0x00
checkResult


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
