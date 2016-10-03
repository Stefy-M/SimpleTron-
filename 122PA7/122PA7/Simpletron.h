#pragma once
#include <iostream>
#include <string>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

class Simpletron {

public:
	Simpletron();
	~Simpletron();

	// setters
	void setAccumalator(int &aCC);
	void setInstructionCounter(int &instrCount);
	void setInstructionRegister(int &InstrReg);
	void setOperationCode(int &opCode);
	void setOperand(int &operand);

	//getters
	int getAccumaltor();
	int getInstructionCounter();
	int getInstructionRegister();
	int getOperationCode();
	int getOperand();




	void fetch();
	void decode();
	void execute();


	void display();
	void Run();

	


private:
	int Accumalator;
	int InstructionCounter;
	int InstructionRegister;
	int OperationCode;
	int Operand;

	int ProgramMem[100];
	int DataMem[10][10];
	fstream SML;
	void fetch(fstream &SML, int ProgramMem[]);
	void decode(int ProgramMem[], int &OperationCode, int &Operand, int &InstructionRegister, int &Accumalator, 
		int &InstructionCounter);
	void execute(int ProgramMem[],int DataMem[][10],int &InstructionRegister, int &OperationCode, int &Operand, 
		int &InstructionCounter, int &Accumalator);


};