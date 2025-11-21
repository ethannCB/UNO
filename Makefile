# ============================================
# Makefile pour le projet TP4_Algo (jeu UNO)
# ============================================

# Variables (tu peux les modifier)
CC = gcc                           # Compilateur C
CFLAGS = -Wall -Wextra -std=c99    # Flags de compilation avec warnings
TARGET = jeu.exe                   # Nom de l'exécutable à créer
SOURCES = carte.c jeu.c main.c     # Fichiers sources (.c) à compiler
OBJECTS = carte.o jeu.o main.o     # Fichiers objets intermédiaires (.o)
HEADERS = carte.h jeu.h            # Fichiers en-têtes (.h)

# ============================================
# Règles (cibles) du Makefile
# ============================================

# Cible par défaut (celle exécutée si tu tapes juste "make")
all: $(TARGET)

# Créer l'exécutable jeu.exe à partir des fichiers objets
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "✓ Compilation réussie ! Exécutable: $(TARGET)"

# Compiler carte.c en carte.o
carte.o: carte.c $(HEADERS)
	$(CC) $(CFLAGS) -c carte.c
	@echo "✓ Compilation de carte.c réussie"

# Compiler jeu.c en jeu.o
jeu.o: jeu.c $(HEADERS)
	$(CC) $(CFLAGS) -c jeu.c
	@echo "✓ Compilation de jeu.c réussie"

# Compiler main.c en main.o
main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c
	@echo "✓ Compilation de main.c réussie"

# Nettoyer les fichiers générés (.o et .exe)
clean:
	del $(OBJECTS) $(TARGET) 2>nul || true
	@echo "✓ Fichiers nettoyés"

# Recompiler tout (clean + all)
rebuild: clean all

# Compiler et exécuter
run: $(TARGET)
	.\$(TARGET)

# Afficher de l'aide
help:
	@echo "Commandes disponibles:"
	@echo "  make              - Compiler le projet (crée jeu.exe)"
	@echo "  make run          - Compiler et exécuter"
	@echo "  make clean        - Supprimer les fichiers compilés"
	@echo "  make rebuild      - Nettoyer et recompiler"
	@echo "  make help         - Afficher cette aide"

# Éviter que make confonde les cibles avec des fichiers réels
.PHONY: all clean rebuild run help
