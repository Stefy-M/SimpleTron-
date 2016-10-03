#include "Simpletron.h"

Simpletron::Simpletron()
{
	int i, j;
	ProgramMem[10];
	DataMem[10][10];
	InstructionCounter = 0;
	InstructionRegister = 0;
	Operand = 0;
	OperationCode = 0;
	Accumalator = 0;
	
	SML.open("SML.txt",ios::in);

	for (i = 0; i < 10; i++) {

		for (j = 0; j < 10; j++) {

			DataMem[i][j] = 0;
			
		}
		
	}
	
}

Simpletron::~Simpletron()
{
	if (SML.is_open()) {
		SML.close();
	}
}

void Simpletron::setAccumalator(int  &aCC)
{
	Accumalator = aCC;
}

void Simpletron::setInstructionCounter(int  &instrCount)
{
	InstructionCounter = instrCount;
}

void Simpletron::setInstructionRegister(int  &InstrReg)
{
	InstructionRegister = InstrReg;
}

void Simpletron::setOperationCode(int & opCode)
{
	OperationCode = opCode;
}

void Simpletron::setOperand(int & operand)
{
	Operand = operand;
}

int Simpletron::getAccumaltor()
{
	return Accumalator;
}

int  Simpletron::getInstructionCounter()
{
	return InstructionCounter;
}

int Simpletron::getInstructionRegister()
{
	return InstructionRegister;
}

int  Simpletron::getOperationCode()
{
	return OperationCode;
}

int  Simpletron::getOperand()
{
	return Operand;
}

void Simpletron::fetch()
{
	int i = 0;
	
	fetch(this->SML, this->ProgramMem);

	/*for (i; i < 10; i++) {
		cout << ProgramMem[i] << endl;
	}*/
}

void Simpletron::decode()
{
	decode(ProgramMem, OperationCode, Operand, InstructionRegister, Accumalator, InstructionCounter);
}

void Simpletron::execute()
{
	execute(ProgramMem,DataMem, InstructionRegister, OperationCode, Operand, InstructionCounter, Accumalator);
}

void Simpletron::display()
{
	int i, j,x;
	cout << "REGISTERS:" << endl;
	cout << "Accumalator:               " << Accumalator << endl;
	cout << "InstructionCounter:        " << InstructionCounter<< endl;
	cout << "InstructionRegister:       " <<InstructionRegister<< endl;
	cout << "OperationCode:             " << OperationCode<< endl;
	cout << "Operand:                   " << Operand<< endl;
	cout << "\n\n";


	cout << "PROGRAM MEMORY" << endl;
	for (x = 0; x < 7; x++) {
		cout << ProgramMem[x] << " ";
		
	}
	cout << "\n\n";
	cout << "DATA MEMORY" << endl;

	for (i = 0; i < 10; i++) {
		
		for (j = 0; j < 10; j++) {
			
			DataMem[i][j];
			cout << DataMem[i][j]<< "     ";
		}
		cout << endl;
	}
}

void Simpletron::fetch(fstream & SML, int ProgramMem[])
{
	char instructorS[100] = " ";
	int instructor = 0;
	char operand = '\0';
	int i =0;


	while (!SML.eof()){
		
		SML >> operand;
		SML.getline(instructorS, 100);

		instructor = atoi(instructorS);
		ProgramMem[i++] = instructor;
		

	}
	

	

	
	
		
		


	
	
	
	
}

void Simpletron::decode(int ProgramMem[], int & OperationCode, int & Operand, 
	int & InstructionRegister, int & Accumalator, int & InstructionCounter)
{
	do {
		
		
		InstructionRegister = ProgramMem[InstructionCounter];
		OperationCode = InstructionRegister / 1000;
		Operand = InstructionRegister % 100;
		execute(ProgramMem,DataMem,InstructionRegister, OperationCode, Operand, InstructionCounter, Accumalator);

		
		InstructionCounter++;
		
		
		
		
		


	} while (OperationCode != 43);

}

void Simpletron::execute(int ProgramMem[],int DataMem[][10], int & InstructionRegister, int & OperationCode, int & Operand, int & InstructionCounter, int & Accumalator)
{
	int user;
	int add;
	int row, column;
	row = (OperationCode / 10) ;
	column = Operand;
	
	switch (OperationCode) {
	case 10:

		display();
		
		row = row - 1;
		cout << "Please Enter a number: ";
		cin >> user;
		DataMem[row][column] = user;
		//setAccumalator(user);
		
		//display();
		
		system("pause");
		system("cls");
		
		
		break;
	case 11:
		row = row - 1;
		
		display();
		cout << "DATA: " << DataMem[row][column] << endl;
		system("pause");
		system("cls");
		break;
	case 20:
	
		row = row - 2;
		Accumalator = DataMem[row][column];
		display();
		cout << "LOADED DATA FROM ACCUMALATOR\n";
		system("pause");
		system("cls");
		
		
		break;
	case 21:
		
		row = row - 2;
		DataMem[row][column] = Accumalator;
		display();
		cout << "STORED DATA FROM ACCUMALATOR TO DATA MEMORY\n";
		system("pause");
		system("cls");
		break;
	case 30:
		
		row = row - 3;
		Accumalator = Accumalator + DataMem[row][column];
		display();
		cout << "ADDITION HAS BEEN ADDED TO ACCUMALATOR\n ";
		system("pause");
		system("cls");
	
		
		break;
	case 31:
		break;
	case 32:
		break;
	case 33:
		break;
	case 40:
		break;
	case 41:
		break;
	case 42:
		break;
	case 43:
		display();
		cout << "HALT HAS BEEN EXECUTED\n";
		cout << "SIMPLETRON IS NOW CLOSING\n";
		break;

	}

}
