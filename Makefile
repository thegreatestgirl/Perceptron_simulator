CC = g++ -std=c++17
GCOV_FLAG = -lgtest -lgtest_main -pthread
MODEL_DIR = MLP/model
CONTROLLER_DIR = MLP/controller
BUILD_DIR = build
VIEW_DIR = MLP/view
APP_NAME = MLP
APP_FILE = MLP.app
APP_SRC_DIR = $(BUILD_DIR)/$(APP_NAME)
APP_DIR = $(HOME)/$(APP_NAME)/
ARCHIVE_NAME = MLP.zip
ARCHIVE_DIR = src/
PRO_FILE = MLP/MLP.pro
TESTFILE = test
MODEL_SOURCES=MLP/model/*.cpp
MODEL_HEADERS=MLP/model/*.h

all: tests

tests: clean
	$(CC) $(MODEL_SOURCES) $(TESTFILE).cpp -o $(TESTFILE) $(GCOV_FLAG)
	./$(TESTFILE)
	@rm -f $(TESTFILE)

clean:
	rm -rf *.out *.o test *.gcno *.gcda *.gcov test.info report *.gch $(TESTFILE)

dvi:
	open dvi.html

dist:
	rm -f $(HOME)/$(ARCHIVE_NAME)
	mkdir -p $(ARCHIVE_DIR)
	@cp -r Makefile $(PRO_FILE) $(MODEL_DIR) $(VIEW_DIR) $(CONTROLLER_DIR) $(ARCHIVE_DIR)
	tar cvzf $(ARCHIVE_NAME) $(ARCHIVE_DIR)
	mv $(ARCHIVE_NAME) $(HOME)
	rm -rf $(ARCHIVE_DIR)

lcov:
	g++ --coverage $(MODEL_SOURCES) $(TESTFILE).cpp -o $(TESTFILE) $(GCOV_FLAG)
	./$(TESTFILE)
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

gcov_report: clean lcov

build: clean
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	cp -r $(PRO_FILE) MLP/main.cpp $(MODEL_DIR) $(VIEW_DIR) $(CONTROLLER_DIR) MLP/view/mainwindow.ui $(BUILD_DIR)
	cd $(BUILD_DIR); qmake $(SMART_CALC_PRO_FILE)
	cd $(BUILD_DIR); make

install: uninstall build
	mkdir -p $(APP_DIR)
	cp -rf $(BUILD_DIR)/$(APP_FILE) $(APP_DIR)
	rm -r $(BUILD_DIR)

uninstall:
	rm -rf $(BUILD_DIR)
	rm -rf $(APP_DIR)

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i MLP/model/*.cpp
	clang-format -i MLP/model/*.h

	clang-format -i MLP/controller/*.cpp
	clang-format -i MLP/controller/*.h

	clang-format -i MLP/view/*.cpp
	clang-format -i MLP/view/*.h


	clang-format -n MLP/model/*.cpp
	clang-format -n MLP/model/*.h

	clang-format -n MLP/controller/*.cpp
	clang-format -n MLP/controller/*.h

	clang-format -n MLP/view/*.cpp
	clang-format -n MLP/view/*.h

