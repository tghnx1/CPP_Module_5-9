#include "Array.hpp"


int main()
{
	Array<std::string> k(3);
	Array<int> l(2);
	Array<int> m(l);

	k[0] = "lol";

	 l[0] = 4;
	 m[0] = 3;
	 Array<std::string> n(5);
	 n = k;
	 n[0] = "kek";

	std::cout << "l: "<< l[0] << std::endl;
	std::cout << "m: " <<  m[0] << std::endl;
	std::cout << "k: "<< k[0] << std::endl;
	std::cout << "n: "<< n[0] << std::endl;

	std::cout << "l size: " << l.size() << std::endl;
	std::cout << "m size: " << m.size() << std::endl;
	std::cout << "k size: " << k.size() << std::endl;
	std::cout << "n size: " << n.size() << std::endl;

	n[2] = "lolos";
	std::cout << "n[2]: " << n[2] << std::endl;
	try {std::cout << "n[228]: " << n[228] << std::endl;}
	catch (const std::exception& g)
	{
		std::cout << "failed because " << g.what() << std::endl;
	}

	return 0;
}
