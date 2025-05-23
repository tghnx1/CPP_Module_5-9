#include "ShrubberyCreationForm.hpp"

//active

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  std::string filename;

  if (!this->checkRequirements(executor))
    return;
  filename = this->getTarget() + "_shrubbery";
  std::ofstream file(filename);

  file <<
      "                                                         .\n"
       "                                              .         ;  \n"
       "                 .              .              ;%     ;;   \n"
       "                   ,           ,                :;%  %;   \n"
       "                    :         ;                   :;%;'     .,   \n"
       "           ,.        %;     %;            ;        %;'    ,;\n"
       "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
       "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
       "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
       "                `%;.     ;%;     %;'         `;%%;.%;'\n"
       "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
       "                    `:%;.  :;bd%;          %;@%;'\n"
       "                      `@%:.  :;%.         ;@@%;'   \n"
       "                        `@%.  `;@%.      ;@@%;         \n"
       "                          `@%%. `@%%    ;@@%;        \n"
       "                            ;@%. :@%%  %@@%;       \n"
       "                              %@bd%%%bd%%:;     \n"
       "                                #@%%%%%:;;\n"
       "                                %@@%%%::;\n"
       "                                %@@@%(o);  . '         \n"
       "                                %@@@o%;:(.,'         \n"
       "                            `.. %@@@o%::;         \n"
       "                               `)@@@o%::;         \n"
       "                                %@@(o)::;        \n"
       "                               .%@@@@%::;         \n"
       "                               ;%@@@@%::;.          \n"
       "                              ;%@@@@%%:;;;. \n"
       "                          ...;%@@@@@%%:;;;;,..    \n\n\n\n\n"
       "               ,@@@@@@@,\n"
       "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
       "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
       "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
       "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
       "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
       "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
       "        |o|        | |         | |\n"
       "       |.|        | |         | |\n"
       "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
       << std::endl;
    file.close();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

// Ortodox Canonical ShrubberyCreationForm:

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137, "ShrubberyTarget")
{
    std::cout << "ShrubberyCreationForm Basic constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const std::string &target)
          : AForm(name, 145, 137, target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& newone) :
AForm(newone)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& newone)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &newone)
    {
        AForm::operator=(newone);
    }
    return (*this);
}