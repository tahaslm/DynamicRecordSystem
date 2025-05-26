CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCS = main.c Proje1.c
HEADERS = Proje1.h
TARGET = program
OBJS = main.o Proje1.o

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

Proje1.o: Proje1.c $(HEADERS)
	$(CC) $(CFLAGS) -c Proje1.c

clean:
	@if exist program.exe del /f program.exe; \
	if exist main.o del /f main.o; \
	if exist Proje1.o del /f Proje1.o; \
	if exist *.d del /f *.d;

clear: clean

run: $(TARGET)
	./$(TARGET)

%.d: %.c
	$(CC) -M $(CFLAGS) $< > $@

-include $(SRCS:.c=.d)


