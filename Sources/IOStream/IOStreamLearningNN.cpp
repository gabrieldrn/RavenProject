#include "IOStreamLearningNN.h"
#include <iostream>
#include <fstream>
#include <list> 
#include <iterator> 
#include <string> 
#include <ctime>

using namespace std;

//-------------------------------- ctor ---------------------------------------
//-----------------------------------------------------------------------------
IOStreamLearningNN::IOStreamLearningNN(int inputs, int outputs):
	nn_inputs(inputs), 
	nn_outputs(outputs), 
	nn_perceptrons(0),
	nn_fileName("NO_FILE_CREATED") 
{}

//-------------------------------- dtor ---------------------------------------
//-----------------------------------------------------------------------------
IOStreamLearningNN::~IOStreamLearningNN() {}

//-----------------------------------------------------------------------------

//------------------------------ createFile -----------------------------------
//
// Create a new .data file with a name formated by the function 
// getCurrentTimeAndDate()
// /!\ The previous opened file will be closed
//-----------------------------------------------------------------------------
void IOStreamLearningNN::createFile()
{
	if (this->nn_workingFile.is_open())
	{
		this->nn_workingFile.close();
		this->nn_fileName = "";
	}
	else
	{
		this->nn_fileName = getCurrentDateAndTime() + ".data";
		this->nn_workingFile.open(nn_fileName);
	}
}

//------------------------------ closeFile ------------------------------------
//
// This function close the current opened file, if there's one.
//-----------------------------------------------------------------------------
void IOStreamLearningNN::closeFile()
{
	if(nn_workingFile.is_open())
		this->nn_workingFile.close();
}

//------------------------------ writeFile ------------------------------------
//
// Reads and writes all appened data in the .data file
//-----------------------------------------------------------------------------
void IOStreamLearningNN::writeFile()
{
	//First line
	this->write(std::to_string(nn_perceptrons) + " 5 1\n");

	//Data
	for (int i = 0; i < nn_perceptrons; i++)
	{
		this->write(
			std::to_string(distList.front()) + " "
			+ std::to_string(hpList.front()) + " "
			+ std::to_string(ammoList.front()) + " "
			+ std::to_string(angleList.front()) + " "
			+ std::to_string(weapList.front())
			+ "\n"
			+ std::to_string(int(shootList.front()))
			+ "\n"
		);

		distList.pop_front();
		hpList.pop_front();
		ammoList.pop_front();
		angleList.pop_front();
		weapList.pop_front();
		shootList.front();
	}
}

//--------------------------------- write -------------------------------------
//
// Writes a string given in parameter, in the opened file
//-----------------------------------------------------------------------------
void IOStreamLearningNN::write(string data)
{
	if (nn_workingFile.is_open())
		this->nn_workingFile << data;
}

//-------------------------- getCurrentDateAndTime ----------------------------
//
// Returns the current date and time in the following format :
// "YYYY_MM_DD_hh_mm_ss"
//-----------------------------------------------------------------------------
string IOStreamLearningNN::getCurrentDateAndTime()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return
		std::to_string(int(1970 + ltm->tm_year)) + "_"
		+ std::to_string(int(1 + ltm->tm_mon)) + "_"
		+ std::to_string(int(ltm->tm_mday)) + "_"
		+ std::to_string(int(1 + ltm->tm_hour)) + "_"
		+ std::to_string(int(1 + ltm->tm_min)) + "_"
		+ std::to_string(int(1 + ltm->tm_sec));
}