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

	// Method to generate a scramble
	string generateScramble(float(&xcube)[48], float(&ycube)[48]);

	// Method to process the scramble and call corresponding UpdateValue methods
	void processScramble(const string& scramble, float(&xcube)[48], float(&ycube)[48]);

	void ResetCube(float(&xcube)[48], float(&ycube)[48]);
	// Helper methods for each move (e.g., UpdateValueR, UpdateValueU)
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
