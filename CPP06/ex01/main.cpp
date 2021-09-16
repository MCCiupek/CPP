#include <iostream>

/* 
*** SERIALIZATION AND DESERIALIZATION ***

Serialization is a mechanism to convert an object into a sequence of bytes 
so that it can be stored in memory. The byte stream, once created, also can be 
streamed across a communication link to a remote receiving end. 

The reverse of serialization is called deserialization, where the data in the 
byte stream is used to reconstruct it to its original object form.

Apart from object persistence, this mechanism is particularly useful in transmitting object 
information in serialized form, say, to the server which, on receiving it, 
can deserialize and create the object format which is its original form. 


*** UINTPTR_T TYPE ***

uintptr_t : unsigned integer type capable of holding a pointer.
A pointer can be converted to any integral type large enough to hold all values of its type (e.g. to std::uintptr_t)


*** REINTERPRET CAST ***
reinterpret_cast is the most dangerous cast, and should be used very sparingly. 
It turns one type directly into another — such as casting the value from one pointer to another, 
or storing a pointer in an int, or all sorts of other nasty things. Largely, the only guarantee 
you get with reinterpret_cast is that normally if you cast the result back to the original type, 
you will get the exact same value (but not if the intermediate type is smaller than the original 
type). There are a number of conversions that reinterpret_cast cannot do, too. It's used primarily 
for particularly weird conversions and bit manipulations, like turning a raw data stream into 
actual data, or storing data in the low bits of a pointer to aligned data.
*/

using std::cout;
using std::endl;
using std::string;

struct Data { int a; double b ; string str; };

void	print_struct(Data * s, string struct_name ) {

	cout << "Struct " << struct_name << ":" << endl;
	cout << "  - a: " << s->a << endl;
	cout << "  - b: " << s->b << endl;
	cout << "  - str: " << s->str << endl;
}

uintptr_t serialize(Data* ptr) {

	cout << ">>> serialization <<<" << endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {

	cout << "<<< deserialization >>>" << endl;
	return reinterpret_cast<Data*>(raw);
}

int main( void )
{
	Data		s1;
	Data *		s2;
	uintptr_t	raw;

	s1.a = 42;
	s1.b = 3.14;
	s1.str = "Quarante-Deux";
	print_struct(&s1, "s1");
	raw = serialize(&s1);
	s2 = deserialize(raw);
	print_struct(s2, "s2");
	return 0;
}