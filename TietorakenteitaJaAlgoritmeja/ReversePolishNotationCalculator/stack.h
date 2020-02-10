#pragma once
#include "utility.h"

const int maxstack = 100;
typedef double Stack_entry;

class Stack {
public:
	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Error_code push(const Stack_entry &item);
	Error_code copy_stack_a(Stack &dest, Stack &source); //test
	Error_code copy_stack_b(Stack &dest, Stack &source); //test
	friend Error_code copy_stack_c(Stack &dest, Stack &source); //test
	void clear();
	bool full() const;
	int size() const;


private:
	int count;
	Stack_entry entry[maxstack];
};

//test extra 
bool full(Stack &s);
Error_code pop_top(Stack &s, Stack_entry &t);
void clear(Stack &s);
int size(Stack &s);
void delete_all(Stack &s, Stack_entry x);