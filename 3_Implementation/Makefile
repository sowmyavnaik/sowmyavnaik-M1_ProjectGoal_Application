#TargetName : Dependencies
#<TAB>commands

Build : calendar_main.c code.c test_calendar.c unity.c
	gcc calendar_main.c code.c test_calendar.c unity.c -o code.out

Run : Build
	./code.out

Clean:
	rm -rf *.o *.out *.i *.s