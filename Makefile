# Makefile pour le jeu UNO

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = uno
OBJS = main.o carte.o jeu.o

# Règle principale
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers objets
main.o: main.c carte.h jeu.h
	$(CC) $(CFLAGS) -c main.c

carte.o: carte.c carte.h
	$(CC) $(CFLAGS) -c carte.c

jeu.o: jeu.c jeu.h carte.h
	$(CC) $(CFLAGS) -c jeu.c

# Nettoyage
clean:
	rm -f $(OBJS) $(TARGET)

# Recompilation complète
rebuild: clean all

# Exécution
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run