#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("anun", 145, 137), target("")
{
	std::cout << "default ctor called for Shrubbery" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tg):AForm("anun", 145, 137)
{
	this->target = tg;
	std::cout << "param ctor called for Shrubbery" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "de-ctor called for Shrubbery" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other):AForm(other.getName(), other.getGrade(), other.getGradeExe())
{
	std::cout << "copy ctor called for Shrubbery" << std::endl;
	this->target = other.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);	
}

/////////////////////////////////////////////////
std::string ShrubberyCreationForm::getTarget()const{return (this->target);}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	if (this->getSign() && executor.getGrade() < this->getGrade())
	{
		std::ofstream fil((this->target + "_shrubbery").c_str());
		fil <<"              _{\' _{\'{\'/}/}/}__"  << std::endl;
		fil <<"             {/{/\'}{/{/\'}(\'}{/\'} _" << std::endl;
		fil <<"           {'/{/\'}{/{/\'}(_)\'}{/{/\'} " << std::endl;
		fil <<"         {/(\'}\'}{/{/\'}\'}{/){/\'}\'}" << std::endl;
		fil <<"        {/{/(_)/}{\'{/)\'}{\'(_){/}/}/}/}" << std::endl;
		fil <<"       _{\'{/{/{\'{/{/(_)/}/}/}{\'(/}/}/\\}" << std::endl;
		fil <<"      {/{/{\'{\'{\'(/}{\'{\'/}/}{\'}(_){\'/}}" << std::endl;
		fil <<"     _{\'{/{\'{/(_)\'}/}{/{/{/\'}\'})\'}{/\'}" << std::endl;
		fil <<"    {/{/{\'{\'(/}{/{\'{\'{\'/})/}{\'(_){]}}\'}" << std::endl;
		fil <<"    {\'{\'/}(_){\'{\'{\'/}/}(_){\'/}{\'/})/}" << std::endl;
		fil <<"   {{\'[/]'{\'/}{/{\'{\'{\'/}/}{\'{\'/}/}\'})" << std::endl;
		fil <<"    {/{\'{\'/}{/){\'{\'{\'/}/}{\'{\'(/}/}\'}" << std::endl;
		fil <<"     {/{\'{\'/}(_){\'{\'{\'(/}/}{\'(_)/}/}}" << std::endl;
		fil <<"       {/({/{\'{/{\'{\'/}(_){\'/}/}\'}/}" << std::endl;
		fil <<"       (_){/{\'/}{\'{\'/}/}{\'{\')/}/}" << std::endl;
		fil <<"         {/{/{\'{\'/}{/{\'{\'{\'(_)/}" << std::endl;
		fil <<"           {/{\'{\'{\'/}/}{\'{\\}/}" << std::endl;
		fil <<"            {){/ {\'/}{\'/} \'}\'}" << std::endl;
		fil <<"              (_)  \'.-'.-/" << std::endl;
		fil <<"          __...--- |'-.-'| --...__" << std::endl;
		fil <<"   _...--   .-'   |'-.-'|  ' -.  *--..__" << std::endl;
		fil <<" -''    ' .  . '    |.'-._| '  . .  '   ''" << std::endl;
		fil <<" .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
		fil <<"          ' ..     |'-_.-|" << std::endl;
		fil <<"  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
		fil <<"              .'   |'- .-|   '." << std::endl;
		fil <<"  ..-'   ' .  '.   `-._.-'   .'  '  - ." << std::endl;
		fil <<"   .-' '        '-._______.-'     '  ." << std::endl;
		fil <<"        .      ~," << std::endl;
		fil <<"    .       .   |\'   .    ' '-." << std::endl;
	}
	else
		throw(AForm::CuldNotExec());
}