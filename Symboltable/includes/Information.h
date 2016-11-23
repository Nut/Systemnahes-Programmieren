#ifndef INFORMATION_H_
#define INFORMATION_H_


class Information {
	public:
		Information(char* lexem, unsigned int key);
		virtual ~Information();
		char* getName();
		bool compareLex(char* lexem);
		unsigned int getKey();

	private:
		char* name;
		unsigned int key;
		int stringCompare(const char *s1, const char *s2);
};


#endif /* INFORMATION_H_ */
