CC = gcc
CFLAGS = -g -Werror -Wextra -Wall -std=c11
GCOV_FLAGS = -fPIC -fprofile-arcs -ftest-coverage
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
endif
ifeq ($(shell uname -s),Darwin)
	browser = open
endif
ifeq ($(shell uname -s), Linux)
	browser = firefox
endif

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.c=%.o)

SRC_DIR = .
SRC_SRC := $(wildcard $(SRC_DIR)/*.c)
SRC_OBJS := $(SRC_SRC:%.c=$(SRC_DIR)/%.o)

EXEC_GCOV = $(TEST_OBJS:%.o=%.out) 

LIB_NAME = s21_decimal.a
INCL_LIB = -L.

DIR = gcov

all: $(SRC_OBJS) $(EXEC_GCOV) execute build_report

$(EXEC_GCOV): %.out: %.o $(TEST_OBJS)
	$(CC) $(TEST_DIR)/$< ./gcov/*.o -o $(TEST_DIR)/$@ $(CHECK_FLAGS) $(GCOV_FLAGS)
	
$(TEST_OBJS): %.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -o $(TEST_DIR)/$@ -c $< 

$(SRC_OBJS): %.o : $(SRC_DIR)/%.c
	@if [ ! -d $(DIR) ] ; then mkdir gcov; fi
	$(CC) $(CFLAGS) -o ./gcov/$@ -c $< $(GCOV_FLAGS)

execute: $(EXEC_GCOV)
	@for test in ./gcov/$^; do \
		./tests/$${test}; \
		echo; \
	done

build_report:
	@gcov $(TEST_DIR)/*.c $(SRC_DIR)/*.c -n
	@lcov --capture --directory $(TEST_DIR) --directory ./gcov --output-file cover.info
	@genhtml cover.info --output-directory OUT
	@$(browser) ./OUT/index.html

%:
	@true
