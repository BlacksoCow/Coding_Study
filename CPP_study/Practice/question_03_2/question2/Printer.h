#ifndef __PRINTER_H__
#define __PRINTER_H__
#define MAXLEN 50

class Printer
{
private:
	char string[MAXLEN + 1];
public:
	void SetString(const char*);
	void ShowString();
};

#endif