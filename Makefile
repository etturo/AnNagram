# Makefile generico per progetti C
# Modifica le variabili secondo le tue necessità

# === CONFIGURAZIONE ===
# Nome dell'eseguibile finale
TARGET = AnNagram

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 
LIBS = 

# Directory
SRCDIR = sources
OBJDIR = obj
INCDIR = includes

# === AUTO-DETECTION DEI FILE ===
# Trova automaticamente tutti i file .c nella directory src/ (o directory corrente)
SOURCES = $(wildcard $(SRCDIR)/*.c)
ifeq ($(SOURCES),)
    # Se non c'è una cartella src/, cerca nella directory corrente
    SOURCES = $(wildcard *.c)
    SRCDIR = .
endif

# Genera i nomi dei file oggetto corrispondenti
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# === REGOLE PRINCIPALI ===

# Regola di default
all: $(TARGET)

# Crea l'eseguibile linkando tutti i file oggetto
$(TARGET): $(OBJECTS)
	@echo "🔗 Linking $(TARGET)..."
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "✅ Build completato: $(TARGET)"

# Regola generica per compilare file .c in file .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "🔨 Compilando $<..."
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# === REGOLE UTILITY ===

# Pulizia file oggetto
clean:
	@echo "🧹 Pulizia file oggetto..."
	rm -rf $(OBJDIR)

# Pulizia completa (oggetti + eseguibile)
fclean: clean
	@echo "🗑️  Pulizia completa..."
	rm -f $(TARGET)

# Ricompilazione completa
re: fclean all

# Esegui il programma dopo averlo compilato
run: $(TARGET)
	@echo "🚀 Eseguendo $(TARGET)..."
	./$(TARGET)

# Debug con gdb
debug: $(TARGET)
	@echo "🐛 Avvio debug con gdb..."
	gdb ./$(TARGET)

# === CONFIGURAZIONI ALTERNATIVE ===

# Build di release (ottimizzato, senza debug)
release: CFLAGS = -Wall -Wextra -std=c99 -O2 -DNDEBUG
release: clean $(TARGET)

# Build di debug (con simboli di debug e sanitizer)
debug-build: CFLAGS += -fsanitize=address -fsanitize=undefined
debug-build: LDFLAGS += -fsanitize=address -fsanitize=undefined
debug-build: clean $(TARGET)

# === HELP ===
help:
	@echo "=== COMANDI DISPONIBILI ==="
	@echo "make [all]     - Compila il progetto"
	@echo "make clean     - Rimuove i file oggetto"
	@echo "make fclean - Rimuove tutto (oggetti + eseguibile)"
	@echo "make re   - Ricompila tutto da zero"
	@echo "make run       - Compila ed esegue il programma"
	@echo "make debug     - Compila e avvia gdb"
	@echo "make release   - Build ottimizzato per release"
	@echo "make debug-build - Build con debug e sanitizer"
	@echo "make help      - Mostra questo aiuto"

# === PHONY TARGETS ===
.PHONY: all clean distclean rebuild run debug info install release debug-build help