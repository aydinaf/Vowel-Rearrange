// Aydin Azari Farhad

#include <iostream>

//global variables:
	int l = 0;//>>>length of word

int checkV(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {  // check for vowels
		return 1;//>>>vowel found
	}
	else {
		return 0;//>>>vowel not found
	}
}

void length(char *ch) {//>>>word length
	for (l = 0; *(ch + l) != '\0'; l++);
}

void arrange(char *ch) {
	length(ch);
	char *str = ch + l-1;//>>>place search at the end of the word
	int index1 = l-1;
	int index2 = l-1;
	while (index1 >= 0) {
		if (checkV(*str)) { //>>>if character is a vowel
			//>>>move char to end:
				char temp = *str;
				for (int pos = index1; pos < index2; pos++) {
					*(ch + pos) = *(ch + pos + 1);
				}//>>>end of method to move to the end
				*(ch + index2) = temp;
				--index2;
		}
		--index1;
		--str;
	}
}

int main()
{
	std::cout << "Enter a word, in lower case only: ";
	char *word = new char[100];
	std::cin >> word;
	arrange(word);
	std::cout << word << std::endl;
	system("pause");
	return 0;
}
