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
};


#endif /* INFORMATION_H_ */
