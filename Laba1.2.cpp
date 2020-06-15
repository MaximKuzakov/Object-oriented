#include "Program.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command input output files"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "\nStart" << endl;
	
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Sort();
	c.Out(ofst);
	c.Clear();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	
	cout << "Done" << endl;
	return 0;
}
