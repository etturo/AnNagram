# Makefile generico per progetti C
# Modifica le variabili secondo le tue necessità

# === CONFIGURAZIONE ===
# Nome dell'eseguibile finale
TARGET = AnNagram

# Compilatore e flag
CC = clang
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
LIBS =

# Directory
SRCDIR = sources
OBJDIR = obj
INCDIR = includes

# === AUTO-DETECTION DEI FILE ===
# Trova automaticamente tutti i file .c nella directory SRCDIR e nella root
SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard *.c)
# Genera i nomi dei file oggetto corrispondenti (solo nome base, messo in obj/)
OBJECTS := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SOURCES)))

# === REGOLE PRINCIPALI ===

# Regola di default
all: $(TARGET)

# Crea l'eseguibile linkando tutti i file oggetto
$(TARGET): $(OBJECTS)
	@echo "🔗 Linking $(TARGET)..."
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "✅ Build completato: $(TARGET)"

# Regola generica per compilare file .c in file .o (sources/)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "🔨 Compilando $<..."
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Regola generica per compilare file .c nella root
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@echo "🔨 Compilando $<..."
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# === REGOLE UTILITY ===

asan: CFLAGS += -fsanitize=address
asan: LDFLAGS += -fsanitize=address
asan: $(TARGET)

# Target per usare il tool leaks di macOS
leaks: $(TARGET)
	@echo "🧪 Test memory leaks con leaks..."
	leaks --atExit -- ./$(TARGET)

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
	lldb ./$(TARGET)

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
	@echo "make [all]        - Compila il progetto"
	@echo "make clean        - Rimuove i file oggetto"
	@echo "make fclean       - Rimuove tutto (oggetti + eseguibile)"
	@echo "make re           - Ricompila tutto da zero"
	@echo "make run          - Compila ed esegue il programma"
	@echo "make debug        - Compila e avvia lldb"
	@echo "make release      - Build ottimizzato per release"
	@echo "make debug-build  - Build con debug e sanitizer"
	@echo "make asan         - Compila con AddressSanitizer"
	@echo "make leaks        - Testa il programma con leaks (macOS)"
	@echo "make help         - Mostra questo aiuto"

# === PHONY TARGETS ===
.PHONY: all clean fclean re run debug release debug-build asan leaks help
