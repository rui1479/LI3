CC := gcc
CFLAGS := -O0 -O -g `pkg-config --cflags glib-2.0`
LDFLAGS := `pkg-config --libs glib-2.0`

DATASET := Dataset_Fase1
SRC_DIR := src
INC_DIR := include
BIN_DIR := build
EXECUTABLE_NAME := programa-principal

all: $(EXECUTABLE_NAME) $(TESTS_EXECUTABLE_NAME)

run: $(EXECUTABLE_NAME) $(DATASET)/drivers.csv $(DATASET)/users.csv $(DATASET)/rides.csv 
	./programa-principal $(DATASET)/drivers.csv $(DATASET)/users.csv $(DATASET)/rides.csv   

$(EXECUTABLE_NAME): $(BIN_DIR)/main.o $(BIN_DIR)/data.o $(BIN_DIR)/drivers.o $(BIN_DIR)/getters.o $(BIN_DIR)/parse.o $(BIN_DIR)/queries.o $(BIN_DIR)/rides.o $(BIN_DIR)/user.o
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

$(BIN_DIR)/parse.o: $(BIN_DIR) $(SRC_DIR)/parse.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/parse.c -o $@

$(BIN_DIR)/queries.o: $(BIN_DIR) $(SRC_DIR)/queries.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/queries.c -o $@

$(BIN_DIR)/rides.o: $(BIN_DIR) $(SRC_DIR)/rides.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/rides.c -o $@

$(BIN_DIR)/user.o: $(BIN_DIR) $(SRC_DIR)/user.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/user.c -o $@

clean:
	rm -rf $(BIN_DIR) $(EXECUTABLE_NAME)