#include "stack.h"

Error_code Stack::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
	  of the Stack.  If the Stack is full,
	  an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
	Error_code outcome = success;
	if (count >= maxstack)
		outcome = overflow;
	else
		entry[count++] = item;
	return outcome;
}

Error_code Stack::copy_stack_a(Stack &dest, Stack &source)
{
	Error_code outcome = success;
	dest = source;
	return outcome;
}

Error_code Stack::copy_stack_b(Stack &dest, Stack &source)
{
	Error_code outcome = success;
	Stack temporary;
	Stack_entry x;
	while (!source.empty()) {
		source.top(x);
		temporary.push(x);
		source.pop();
	}
	while (!temporary.empty()) {
		temporary.top(x);
		source.push(x);
		dest.push(x);
		temporary.pop();
	}
	return outcome;
}

Error_code copy_stack_c(Stack &dest, Stack &source)
{
	Error_code outcome = success;
	dest.count = source.count;
	for (int i = source.count - 1; i >= 0; i--) {
		dest.entry[i] = source.entry[i];
	}
	return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
	  the Stack is removed.  If the Stack
	  is empty, an Error_code of underflow is returned.
*/

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else --count;
	return outcome;
}


Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
	  the Stack is returned in item.  If the Stack
	  is empty an Error_code of underflow is returned.
*/

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
	  Otherwise false is returned.
*/

{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}


Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
	count = 0;
}

void Stack::clear()
{
	while (count > 0)
		--count;

}

bool Stack::full() const
{
	if (count == maxstack)
		return true;
	else
		return false;
}

int Stack::size() const
{
	return count;
}



bool full(Stack & s)
{
	return s.full();
}

Error_code pop_top(Stack &s, Stack_entry &t)
{
	Error_code outcome = success;
	if (s.empty()) {
		outcome = underflow;
	}
	else {
		Stack_entry x;
		s.top(x);
		t = x;
		s.pop();
	}
	return outcome;
}

void clear(Stack & s)
{
	s.clear();
}

int size(Stack & s)
{
	return s.size();
}

void delete_all(Stack & s, Stack_entry x)
{
	Stack_entry a;
	Stack temp;
	while (!s.empty()) {
		s.top(a);
		//cout << a << " "; //tarkistusta varten
		if (a != x) {
			temp.push(a);
		}
		s.pop();
	}
	while (!temp.empty()) {
		temp.top(a);
		s.push(a);
		temp.pop();
	}
	/* 
	while (!s.empty()) {
		s.top(a);
		cout << a << " "; //tarkistusta varten
		s.pop();
	}
	*/
}
