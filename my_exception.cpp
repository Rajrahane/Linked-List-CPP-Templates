#include<exception>
using namespace std;
class NoSuchElementException:public exception{
	public:
		const char* what()const throw(){
			return "NoSuchElementException\n";
		}
};
