#pragma once
#ifndef CUBESCRAMBLE_H
#define CUBESCRAMBLE_H

#include <string>
#include <vector>
#include <utility> 


using namespace std;

class CubeScramble {
public:
	// Constructor
	CubeScramble();
	float solvedx[48] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.15, 0.15, 0.15, 0.25, 0.25, 0.35, 0.35, 0.35, 0.50, 0.50, 0.50, 0.60, 0.60, 0.70, 0.70, 0.70, -0.55, -0.55, -0.55, -0.45, -0.45, -0.35, -0.35, -0.35, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.1, -0.1, -0.1, -0.1, -0.1, -0.1 };
	float solvedy[48] = { 0.45, 0.35, 0.25, 0.1, 0.0, -0.1, -0.25, -0.35, -0.45, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.45, 0.35, 0.25, 0.1, 0.0, -0.1, -0.25, -0.35, -0.45, 0.45, 0.25, 0.1, -0.1, -0.25, -0.45 };
	// Method to generate a scramble
	string generateScramble(float(&xcube)[48], float(&ycube)[48]);
	void processScramble(const string& scramble, float(&xcube)[48], float(&ycube)[48]);
	void ResetCube(float(&xcube)[48], float(&ycube)[48]);
	bool isSolved(float(&xcube)[48], float(&ycube)[48], bool isTimerRunning);

	void updateValueR(float& x, float& y);
	void updateValueRPrime(float& x, float& y);
	void updateValueU(float& x, float& y);
	void updateValueUPrime(float& x, float& y);
	void updateValueD(float& x, float& y);
	void updateValueDPrime(float& x, float& y);
	void updateValueL(float& x, float& y);
	void updateValueLPrime(float& x, float& y);
	void updateValueF(float& x, float& y);
	void updateValueFPrime(float& x, float& y);
	void updateValueB(float& x, float& y);
	void updateValueBPrime(float& x, float& y);
};

#endif
