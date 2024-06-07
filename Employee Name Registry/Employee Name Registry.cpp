#include <iostream.h>
#include <fstream.h>
#include <algorithm>
ofstream outputFile;
ifstream inputFile;
int main() {
	std::string EmployeeName;
	int value = 1, ArraySize = 1, counter1 = 1,counter2 =0 ;
	outputFile.open("employee_names.txt",ios::out);
	if (outputFile.fail()) {
			cerr << "\n\n Error opening file for Writing.\n" << endl;
			return 1;
		}
	cout << "\t\t\tEnter employee names and Type 'done' to Finish\n";
	cout << "\t\t==============================================================\n";
	do {
			cout << " Enter Employee Name: ";
			cin >> EmployeeName;
			if (EmployeeName != "done"){
					outputFile << EmployeeName << "\n";
				}else{
					value = 2;
				}
		}while (value == 1);
	outputFile.close();
	inputFile.open("employee_names.txt",ios::in);
	if (inputFile.fail()) {
			cerr << "\n\n Error opening file for Reading.\n" << endl;
			return 1;
		}
	cout << "\n\n\t\t\tAlphabetically Sorted Employee Names\n";
	cout << "\t\t====================================================\n";
	std::string Employee[10];
	while (!inputFile.eof()){
			for (int i=counter2;i<ArraySize;++i){
					inputFile>>Employee[i];
				}
			counter2++;
			ArraySize++;
		}
	ArraySize = (ArraySize - 2);
	sort(Employee,Employee + ArraySize);
	for (int z=0;z<ArraySize;++z){
			cout<<" Employee "<<counter1 <<" : " << Employee[z]<< endl;
			counter1++;
		}
	inputFile.close();
	return 0;
}

