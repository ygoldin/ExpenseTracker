# created by Yael Goldin

HEADERS = Utils.h Expense.h BalanceTable.h Group.h
OBJECTS = Utils.o Expense.o BalanceTable.o Group.o

main: main.o $(OBJECTS)
	g++ -Wall -g -std=c++11 -o main main.o $(OBJECTS)

main.o: main.cpp $(HEADERS)
	g++ -Wall -g -std=c++11 -c main.cpp

# individual files
Utils.o: Utils.cpp Utils.h
	g++ -Wall -g -std=c++11 -c Utils.cpp

Expense.o: Expense.cpp Expense.h Utils.h
	g++ -Wall -g -std=c++11 -c Expense.cpp

BalanceTable.o: BalanceTable.cpp BalanceTable.h
	g++ -Wall -g -std=c++11 -c BalanceTable.cpp

Group.o: Group.cpp Group.h
	g++ -Wall -g -std=c++11 -c Group.cpp

# clean
clean:
	rm -rf main *.o *~ main.dSYM
