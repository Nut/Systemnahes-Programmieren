#ifndef INFORMATION_H_
#define INFORMATION_H_


class Information {
	public:
		Information(char* lexem);
		virtual ~Information();
		char* getName();
		bool compareLex(char* lexem);

	private:
		char* name;
		int myStrCmp(const char *s1, const char *s2);
};


#endif /* INFORMATION_H_ */
