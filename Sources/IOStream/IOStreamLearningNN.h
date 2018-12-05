#ifndef IOSTREAM_LEARNING_NEURAL_NETWORK_H
#define IOSTREAM_LEARNING_NEURAL_NETWORK_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   IOStreamLearningNN.h
//
//  Author: Gabriel Derrien & Baptiste Roupain
//
//  Desc:   Class handling data writing to define perceptrons of the artificial
//			neural network (FANN lib) of the learning bot. It stores data and
//			creates a proper .data file.
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <ctime>
#include <list>
#include <string>

using namespace std;

class IOStreamLearningNN
{
private:

	ofstream nn_workingFile;
	string nn_fileName;

	int nn_inputs;
	int nn_outputs;

	double nn_distanceToTarget;
	int nn_healthPoints;
	int nn_ammunitions;
	double nn_angle;
	int nn_weaponType;
	bool nn_shootDecision;

	list <double> distList, angleList;
	list <int> hpList, ammoList, weapList;
	list <bool> shootList;

	int nn_perceptrons;

public:
	IOStreamLearningNN(int inputs, int outputs);
	~IOStreamLearningNN();

	void createFile();
	void closeFile();
	void write(string data);
	void writeFile();

	void setDistanceToTarget(double value) { nn_distanceToTarget = value; }
	void setHealthPoints(int value) { nn_healthPoints = value; }
	void setAmmunitions(int value) { nn_ammunitions = value; }
	void setAngle(double value) { nn_angle = value; }
	void setWeaponType(int value) { nn_weaponType = value; }
	void setShootDecision(bool value) { nn_shootDecision = value; }
//	void pushIntoList(int Health, int AmmoLeft, doouble ShootingAngle, double Distance, int currentWeaponID);
	void appendLine()
	{
		distList.push_back(nn_distanceToTarget);
		hpList.push_back(nn_healthPoints);
		ammoList.push_back(nn_ammunitions);
		angleList.push_back(nn_angle);
		weapList.push_back(nn_weaponType);
		shootList.push_back(nn_shootDecision);
		nn_perceptrons++;
	};
	
	string getCurrentDateAndTime();
	string getWorkingFileName() { return nn_fileName; };
};

#endif
