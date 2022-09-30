#include <iostream>
#include <string>

using namespace std;

class Histogram {
	string str;
public:
	Histogram(string s);
	void put(string s);
	void putc(char c);
	void print();
};
Histogram::Histogram(string s) {
	this->str = s;
}
void Histogram::put(string s) {
	this->str += s;
}

void Histogram::putc(char c) {
	this->str += c;
}

void Histogram::print() {
	int count = 0;
	int alphaNum[26] = {0};
	cout << str << endl << endl;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			count++;
			alphaNum[tolower(str[i]) - 'a'] += 1;
		}
	}
	cout << "총 알파벳 수" << count << endl << endl;

	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		cout << c << " (" << alphaNum[i] << ")\t: ";
		for (int j = 0; j < alphaNum[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
}
int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
