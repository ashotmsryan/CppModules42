#include "Replace.hpp"
#include <unistd.h>

std::string GetFileName(char *s)
{
	int i = -1;
	std::string name;
	while(s && s[++i] && s[i] != '.')
		name.push_back(s[i]);
	name.append(".replace");
	return (name);
}

std::string GetNew(char **argv, std::string neww, size_t i)
{
	std::string tmp = neww;
	std::string	last = neww;

	tmp = tmp.substr(0, i);
	tmp.append(argv[3]);
	last = last.substr((i + strlen(argv[2])));
	tmp.append(last);
	return (tmp);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string	content;
		std::string	neww;
		std::ifstream file;
		std::string tmp;
		size_t		i = 0;
		int			flag = 0;

		file.open(argv[1]); //std::stream file(argv[1]);
		if (file.fail())
		{
			std::cout << "No such a file !" << std::endl;
			exit(1);
		}
		while(file.good())
		{
			getline(file, neww);
			if (!file.eof() && !neww[0])
				neww.push_back('\n');
			tmp = neww;
			flag = 0;
			i = 0;
			while (i != std::string::npos)
			{
				if (flag == 1)
					i = neww.find(argv[2], i + strlen(argv[3]));
				else
				{
					i = neww.find(argv[2], i);
					flag++;
				}
				if (i != std::string::npos)
					neww = GetNew(argv, neww, i);
			}
			content += neww; //content = content.append(neww); 
			if (neww[0] && neww[0] != '\n')
				content.push_back('\n');
		}
		file.close();
		if (content[0])
		{
			std::ofstream newfile (GetFileName(argv[1]), std::ofstream::out); //open to write
			newfile << content;
			newfile.close();
		}
	}
	else
		std::cout << "Wrong quantity of inputs!" << std::endl;
	return (0);
}