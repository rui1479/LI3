CC := gcc
CFLAGS := -O0 -g `pkg-config --cflags glib-2.0`
LDFLAGS := `pkg-config --libs glib-2.0`
DATASET := Dataset_Fase1
SRC_DIR := src
INC_DIR := include
BIN_DIR := build
EXECUTABLE_NAME := programa-principal
EXECUTABLE_TEST := programa-testes

all: $(EXECUTABLE_NAME) $(TESTS_EXECUTABLE_NAME)
all: $(EXECUTABLE_NAME) $(EXECUTABLE_TEST)

$(EXECUTABLE_NAME): $(BIN_DIR)/main.o $(BIN_DIR)/data.o $(BIN_DIR)/drivers.o $(BIN_DIR)/getters.o $(BIN_DIR)/catalogos.o $(BIN_DIR)/queries.o $(BIN_DIR)/rides.o $(BIN_DIR)/user.o $(BIN_DIR)/validadur.o $(BIN_DIR)/menu.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(EXECUTABLE_TEST): $(BIN_DIR)/testes.o $(BIN_DIR)/data.o $(BIN_DIR)/drivers.o $(BIN_DIR)/getters.o $(BIN_DIR)/catalogos.o $(BIN_DIR)/queries.o $(BIN_DIR)/rides.o $(BIN_DIR)/user.o $(BIN_DIR)/validadur.o $(BIN_DIR)/menu.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BIN_DIR)/main.o: $(BIN_DIR) $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/main.c -o $@

$(BIN_DIR)/data.o: $(BIN_DIR) $(SRC_DIR)/data.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/data.c -o $@

$(BIN_DIR)/drivers.o: $(BIN_DIR) $(SRC_DIR)/drivers.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/drivers.c -o $@

$(BIN_DIR)/getters.o: $(BIN_DIR) $(SRC_DIR)/getters.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/getters.c -o $@

$(BIN_DIR)/catalogos.o: $(BIN_DIR) $(SRC_DIR)/catalogos.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/catalogos.c -o $@

$(BIN_DIR)/queries.o: $(BIN_DIR) $(SRC_DIR)/queries.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/queries.c -o $@

$(BIN_DIR)/rides.o: $(BIN_DIR) $(SRC_DIR)/rides.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/rides.c -o $@

$(BIN_DIR)/user.o: $(BIN_DIR) $(SRC_DIR)/user.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/user.c -o $@

$(BIN_DIR)/validadur.o: $(BIN_DIR) $(SRC_DIR)/validadur.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/validadur.c -o $@

$(BIN_DIR)/menu.o: $(BIN_DIR) $(SRC_DIR)/menu.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/menu.c -o $@

$(BIN_DIR)/testes.o: $(BIN_DIR) $(SRC_DIR)/testes.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/testes.c -o $@

run1: 
	./programa-principal Dataset_Fase1 Dataset_Fase1/input.txt

run2: 
	./programa-principal Dataset_Fase2 Dataset_Fase1/input.txt  

run3: 
	./programa-principal Dataset_Fase3 Dataset_Fase1/input.txt  

run4: 
	./programa-principal Dataset_Fase4 Dataset_Fase1/input.txt  

menu:
	./programa-principal

test: 
	./programa-testes Dataset_Fase1

clean:
	rm -rf $(BIN_DIR) $(EXECUTABLE_NAME)
	rm -rf $(BIN_DIR) $(EXECUTABLE_NAME) $(EXECUTABLE_TEST)