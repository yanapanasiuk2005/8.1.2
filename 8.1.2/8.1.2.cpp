#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(const char* str, const char c, int k, int i)
{
	if (c == str[i])
		k++;
	if (str[i + 1] != '\0')
		Count(str, c, k, i + 1);
	else
		return k;
}
int Count2(const char* str, const char d, int k, int i)
{
	if (d == str[i])
		k++;
	if (str[i + 1] != '\0')
		Count2(str, d, k, i + 1);
	else
		return k;
}
int Count3(const char* str, const char f, int k, int i)
{
	if (f == str[i])
		k++;
	if (str[i + 1] != '\0')
		Count3(str, f, k, i + 1);
	else
		return k;
}
char* Change(char* dest, const char* str, char* t, int i, int len)
{
	if (i < len - 1)
	{
		if ((str[i] == '+' && str[i + 1] == '+') || (str[i] == '=' &&
			str[i + 1] == '=') || (str[i] == '-' && str[i + 1] == '-'))
		{
			strcat(t, "***");
			return Change(dest, str, t + 3, i + 2, len);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i, len);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char str[101];
	char c = '+';
	char d = '-';
	char f = '=';
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	size_t len = strlen(str);
	size_t maxlen = len;
	char* tmp = new char[maxlen];
	tmp[0] = '\0';
	size_t i = 0;
	size_t last = strlen(tmp);
	cout << "String contains " << Count(str, c, 0, 0) << " symbols '+'" <<
		endl;
	cout << "String contains " << Count2(str, d, 0, 0) << " symbols '-'"
		<< endl;
	cout << "String contains " << Count3(str, f, 0, 0) << " symbols '='"
		<< endl;
	char* dest1 = new char[151];
	dest1[0] = '/0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0, len);
	cout << "Modified string: " << dest2 << endl;
	return 0;
}