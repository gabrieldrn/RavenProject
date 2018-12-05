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
// IOStreamLearningNN::IOStreamLearningNN(int inputs, int outputs):
//	nn_inputs(inputs),
//	nn_outputs(outputs),
//	nn_perceptrons(0),
//	nn_fileName("NO_FILE_CREATED")
//{}
IOStreamLearningNN::IOStreamLearningNN(int inputs, int outputs)
{
	this->nn_inputs = inputs;
	this->nn_outputs = outputs;
	this->nn_perceptrons = 0;
	this->nn_fileName = "NO FILE CREATED";
}
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
	}
	this->nn_fileName = getCurrentDateAndTime() + ".data";
	this->nn_workingFile.open(nn_fileName);
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
	this->write(std::to_string(nn_perceptrons) + " " + std::to_string(this->nn_inputs) + " " + std::to_string(this->nn_outputs) + "\n");
	double dist, angleLs;
	int hpLs, ammoLs, weapLs;
	bool shootLs;
	//Data
	for (int i = 0; i < nn_perceptrons; i++)
	{
		if (!empty(distList)) dist = distList.front();
		else dist = 0;
		if (!empty(hpList)) hpLs = hpList.front();
		else hpLs = 0;
		if (!empty(ammoList)) ammoLs = ammoList.front();
		else ammoLs = 0;
		if (!empty(angleList)) angleLs = angleList.front();
		else angleLs = 0;
		if (!empty(weapList)) weapLs = weapList.front();
		else weapLs = 0;
		if (!empty(shootList)) shootLs = shootList.front();
		else shootLs = 0;

		this->write(
			std::to_string(dist) + " "
			+ std::to_string(hpLs) + " "
			+ std::to_string(ammoLs) + " "
			+ std::to_string(angleLs) + " "
			+ std::to_string(weapLs)
			+ "\n"
			+ std::to_string(shootLs)
			+ "\n"
		);
		distList.pop_front();
		hpList.pop_front();
		ammoList.pop_front();
		angleList.pop_front();
		weapList.pop_front();
		shootList.pop_front();
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
