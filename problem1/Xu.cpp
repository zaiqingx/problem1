#include <iostream>
#include <string>

int main() {
	//s variable stores the input of the program.
	std::string s;
	std::cin >> s;

	//state variable stores the input of the previous char
	char state = s[0];
	//n1 variable is the output of the first policy
	//n2 variable is the output of the second policy
	//n3 variable is the output of the third policy
	int n1 = 0, n2 = 0, n3 = 0;

	//The first two characters are treatly separately first.
	if (state == 'U')
	{
		if (s[1] == 'U')
		{
			//The input string begins with "UU"
			n2 = 1;
		}
		else
		{
			//The input string begins with "UD"
			n1 = 2;
			n2 = 1;
		}/*else*/
	}
	else
	{
		if (s[1] == 'U')
		{
			//The input string begins with "DU"
			n1 = 1;
			n2 = 2;
		}
		else
		{
			//The input string begins with "DD"
			n1 = 1;
		}/*else*/
	}/*else*/

	n3 = (state != s[1]);
	state = s[1];

	//After the special treatment of the first two characters, we deal with the rest.
	for (int count = 2; count < s.length(); count++)
	{
		switch (s[count])
		{
		case 'U':
			n2 += 2;
			if (state == 'D')
				n3++;
			break;
		case 'D':
			n1 += 2;
			if (state == 'U')
				n3++;
			break;
		}/*switch*/

		state = s[count];
	}/*for*/

	//output the final results
	std::cout << n1 << std::endl << n2 << std::endl << n3;
	return 0;
}/*main*/