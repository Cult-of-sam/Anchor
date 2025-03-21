BINARY = anchor

SOURCE_DIR = src
OBJECT_DIR = obj

#CC = clang
CC_FLAGS = -Wall -Werror -I $(SOURCE_DIR) -g -W

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))

.PHONY: all
all: $(BINARY)

$(BINARY): $(OBJECTS) $(OBJECT_DIR)
	$(CC) $(CC_FLAGS) $(OBJECTS) -o $@

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c $(OBJECT_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) -r $(OBJECT_DIR)
	$(RM) $(BINARY)