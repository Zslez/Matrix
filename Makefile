main = main.cpp
exe = main


compile:
	@g++ -o $(exe) $(main)


run:
	@$(exe)


all: compile run
