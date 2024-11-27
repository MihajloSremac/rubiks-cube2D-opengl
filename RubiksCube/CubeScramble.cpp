#include "CubeScramble.h"
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <functional>



CubeScramble::CubeScramble() {

}

// Method to generate a random scramble
string CubeScramble::generateScramble(float(&xcube)[48], float(&ycube)[48]) {
	vector<string> faces = { "U", "D", "L", "R", "F", "B" };
	vector<string> modifiers = { "", "'", "2" };
	string scramble;
	string lastFace = "";

	int moves = 25;

	srand(time(0));

	for (int i = 0; i < moves; ++i) {
		string face;

		do {
			face = faces[rand() % faces.size()];
		} while (face == lastFace);

		string modifier = modifiers[rand() % modifiers.size()];
		scramble += face + modifier + " ";
		lastFace = face;
	}

	processScramble(scramble, xcube, ycube);
	return scramble;
}


void CubeScramble::ResetCube(float (&xcube)[48], float (&ycube)[48]) {
	for (int i = 0; i < 48; i++) {
		xcube[i] = solvedx[i];
		ycube[i] = solvedy[i];
	}
}

bool areArraysEqual(const float* arr1, const float* arr2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (std::fabs(arr1[i] - arr2[i]) > 1e-6) {
			return false;
		}
	}
	return true;
}

bool CubeScramble::isSolved(float(&xcube)[48], float(&ycube)[48], bool isTimerRunning) {
	return areArraysEqual(xcube, solvedx, 48) && areArraysEqual(ycube, solvedy, 48) && isTimerRunning;
}

void CubeScramble::processScramble(const string& scramble, float(&xcube)[48], float(&ycube)[48]) {
	string move;
	ResetCube(xcube, ycube);
	for (size_t i = 0; i < scramble.size(); ++i) {
		if (scramble[i] == ' ') {
			// Execute the correct UpdateValue method inside a loop for each move
			if (move == "R") {
				for (int i = 0; i < 48; ++i) {
					updateValueR(xcube[i], ycube[i]);
				}
			}
			else if (move == "R'") {
				for (int i = 0; i < 48; ++i) {
					updateValueRPrime(xcube[i], ycube[i]);
				}
			}
			else if (move == "R2") {
				for (int i = 0; i < 48; ++i) {
					updateValueR(xcube[i], ycube[i]);
					updateValueR(xcube[i], ycube[i]);  
				}
			}
			else if (move == "U") {
				for (int i = 0; i < 48; ++i) {
					updateValueU(xcube[i], ycube[i]);
				}
			}
			else if (move == "U'") {
				for (int i = 0; i < 48; ++i) {
					updateValueUPrime(xcube[i], ycube[i]);
				}
			}
			else if (move == "U2") {
				for (int i = 0; i < 48; ++i) {
					updateValueU(xcube[i], ycube[i]);
					updateValueU(xcube[i], ycube[i]);  
				}
			}
			else if (move == "D") {
				for (int i = 0; i < 48; ++i) {
					updateValueD(xcube[i], ycube[i]);
				}
			}
			else if (move == "D'") {
				for (int i = 0; i < 48; ++i) {
					updateValueDPrime(xcube[i], ycube[i]);
				}
			}
			else if (move == "D2") {
				for (int i = 0; i < 48; ++i) {
					updateValueD(xcube[i], ycube[i]);
					updateValueD(xcube[i], ycube[i]);  
				}
			}
			else if (move == "L") {
				for (int i = 0; i < 48; ++i) {
					updateValueL(xcube[i], ycube[i]);
				}
			}
			else if (move == "L'") {
				for (int i = 0; i < 48; ++i) {
					updateValueLPrime(xcube[i], ycube[i]);
				}
			}
			else if (move == "L2") {
				for (int i = 0; i < 48; ++i) {
					updateValueL(xcube[i], ycube[i]);
					updateValueL(xcube[i], ycube[i]);  
				}
			}
			else if (move == "F") {
				for (int i = 0; i < 48; ++i) {
					updateValueF(xcube[i], ycube[i]);
				}
			}
			else if (move == "F'") {
				for (int i = 0; i < 48; ++i) {
					updateValueFPrime(xcube[i], ycube[i]);
				}
			}
			else if (move == "F2") {
				for (int i = 0; i < 48; ++i) {
					updateValueF(xcube[i], ycube[i]);
					updateValueF(xcube[i], ycube[i]);  
				}
			}
			else if (move == "B") {
				for (int i = 0; i < 48; ++i) {
					updateValueB(xcube[i], ycube[i]);
				}
			}
			else if (move == "B'") {
				for (int i = 0; i < 48; ++i) {
					updateValueBPrime(xcube[i], ycube[i]);
				}
			}
			else if (move == "B2") {
				for (int i = 0; i < 48; ++i) {
					updateValueB(xcube[i], ycube[i]);
					updateValueB(xcube[i], ycube[i]); 
				}
			}

			move.clear(); 
		}
		else {
			move += scramble[i];  
		}
	}
}


void CubeScramble::updateValueR(float& xcube, float& ycube) {

	//Beli deo na plavu stranu
	if (ycube < 0.46 && ycube> 0.36 && xcube < 0.01 && xcube > -0.01) {
		ycube = -0.1;
		xcube = 0.50;
	}
	else if (ycube < 0.36 && ycube > 0.26 && xcube < 0.01 && xcube > -0.01) {
		ycube = 0.0;
		xcube = 0.50;
	}
	else if (ycube < 0.26 && ycube > 0.16 && xcube < 0.01 && xcube > -0.01) {
		ycube = 0.1;
		xcube = 0.50;
	}
	//Plava strana na zuti deo
	else if (ycube < 0.16 && ycube > 0.06 && xcube < 0.51 && xcube > 0.41) {
		ycube = -0.45;
		xcube = -0.0;
	}
	else if (ycube < 0.06 && ycube > -0.06 && xcube < 0.51 && xcube > 0.41) {
		ycube = -0.35;
		xcube = -0.0;
	}
	else if (ycube < -0.06 && ycube > -0.16 && xcube < 0.51 && xcube > 0.41) {
		ycube = -0.25;
		xcube = -0.0;
	}
	else if (ycube < 0.16 && ycube > -0.46 && xcube < 0.01 && xcube > -0.01) {
		ycube += 0.35;
	}
	//Rotacija desne strane
	//Gornja leva ivica
	if (xcube > 0.06 && xcube < 0.16 && ycube > 0.01 && ycube < 0.11)
		xcube = 0.35;

	////Gornja ivica
	else if (xcube > 0.16 && xcube < 0.26 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.0;
		xcube = 0.35;
	}

	////Gornja desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > 0.01 && ycube < 0.11)
		ycube = -0.1;

	////Desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.1;
		xcube = 0.25;
	}

	////Donja desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.19 && ycube < -0.09)
		xcube = 0.15;

	////Donja ivica
	else if (xcube > 0.16 && xcube < 0.26 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.0;
		xcube = 0.15;
	}

	////Donja leva ivica
	else if (xcube > 0.06 && xcube < 0.16 && ycube > -0.19 && ycube < -0.09)
		ycube = 0.1;

	////Leva ivica
	else if (xcube > 0.06 && xcube < 0.16 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.1;
		xcube = 0.25;
	}
}
void CubeScramble::updateValueRPrime(float& xcube, float& ycube) {
	if (ycube > 0.06 && ycube < 0.11 && xcube < 0.51 && xcube > 0.46) {
		ycube = 0.25;
		xcube = 0.0;
	}
	else if (ycube > -0.01 && ycube < 0.06 && xcube < 0.51 && xcube > 0.46) {
		ycube = 0.35;
		xcube = 0.0;
	}
	else if (ycube > -0.11 && ycube < -0.01 && xcube < 0.51 && xcube > 0.46) {
		ycube = 0.45;
		xcube = 0.0;
	}

	//Zuti deo na plavu stranu
	else if (ycube > -0.46 && ycube < -0.36 && xcube < 0.01 && xcube > -0.01) {
		ycube = 0.1;
		xcube = 0.50;
	}
	else if (ycube > -0.36 && ycube < -0.26 && xcube < 0.01 && xcube > -0.01) {
		ycube = 0.0;
		xcube = 0.50;
	}
	else if (ycube > -0.26 && ycube < -0.16 && xcube < 0.01 && xcube > -0.01) {
		ycube = -0.1;
		xcube = 0.50;
	}
	//ostalo
	else if (ycube > -0.11 && ycube < 0.46 && xcube < 0.01 && xcube > -0.01) {
		ycube -= 0.35;
	}

	//Rotacija desne strane
	//Gornja leva ivica
	if (xcube > 0.06 && xcube < 0.16 && ycube > 0.01 && ycube < 0.11) {
		xcube = 0.15;
		ycube = -0.1;
	}

	//Gornja ivica
	else if (xcube > 0.16 && xcube < 0.26 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.0;
		xcube = 0.15;
	}

	//Gornja desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.1;
		xcube = 0.15;
	}

	//Desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.1;
		xcube = 0.25;
	}

	//Donja desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.19 && ycube < -0.09) {
		xcube = 0.35;
		ycube = 0.1;
	}

	//Donja ivica
	else if (xcube > 0.16 && xcube < 0.26 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.0;
		xcube = 0.35;
	}

	//Donja leva ivica
	else if (xcube > 0.06 && xcube < 0.16 && ycube > -0.19 && ycube < -0.09)
	{
		ycube = -0.1;
		xcube = 0.35;
	}

	//Leva ivica
	else if (xcube > 0.06 && xcube < 0.16 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.1;
		xcube = 0.25;
	}

}
void CubeScramble::updateValueU(float& xcube, float& ycube) {
	if (xcube + -0.34 < -0.56 && ycube > 0.06 && ycube < 0.16)
		xcube += 1.05;
	else if (ycube > 0.06 && ycube < 0.16)
		xcube -= 0.35;
	//Gornji desni cosak
	if (xcube > -0.09 && xcube < 0.01 && ycube < 0.46 && ycube > 0.36)
		ycube = 0.25;

	//Desna ivica
	else if (xcube > -0.09 && xcube < 0.01 && ycube < 0.36 && ycube > 0.26) {
		ycube = 0.25;
		xcube = -0.1;
	}

	//Donji desni cosak
	else if (xcube > -0.09 && xcube < 0.01 && ycube < 0.26 && ycube > 0.16)
		xcube = -0.2;

	//Donja ivica
	else if (xcube > -0.19 && xcube < -0.09 && ycube < 0.26 && ycube > 0.16) {
		ycube = 0.35;
		xcube = -0.2;
	}

	////Donji levi cosak
	else if (xcube > -0.29 && xcube < -0.19 && ycube < 0.26 && ycube > 0.16)
		ycube = 0.45;

	////Leva ivica
	else if (xcube > -0.29 && xcube < -0.19 && ycube < 0.36 && ycube > 0.26) {
		ycube = 0.45;
		xcube = -0.1;
	}

	////Gornji levi cosak
	else if (xcube > -0.29 && xcube < -0.19 && ycube < 0.46 && ycube > 0.36)
		xcube = 0.0;

	//Gornja ivica
	else if (xcube > -0.19 && xcube < -0.09 && ycube < 0.46 && ycube > 0.36) {
		ycube = 0.35;
		xcube = 0.0;
	}

}
void CubeScramble::updateValueUPrime(float& xcube, float& ycube) {
	if (xcube + 0.34 > 0.71 && ycube > 0.06 && ycube < 0.16)
		xcube -= 1.05;
	else if (ycube > 0.06 && ycube < 0.16)
		xcube += 0.35;

	//Gornji desni cosak
	if (xcube > -0.09 && xcube < 0.01 && ycube < 0.46 && ycube > 0.36)
		xcube = -0.2;

	//Desna ivica 
	else if (xcube > -0.09 && xcube < 0.01 && ycube < 0.36 && ycube > 0.26) {
		ycube = 0.45;
		xcube = -0.1;
	}

	//Donji desni cosak
	else if (xcube > -0.09 && xcube < 0.01 && ycube < 0.26 && ycube > 0.16)
		ycube = 0.45;

	//Donja ivica
	else if (xcube > -0.19 && xcube < -0.09 && ycube < 0.26 && ycube > 0.16) {
		ycube = 0.35;
		xcube = 0.0;
	}

	////Donji levi cosak
	else if (xcube > -0.31 && xcube < -0.19 && ycube < 0.26 && ycube > 0.16)
		xcube = 0.0;

	////Leva ivica
	else if (xcube > -0.31 && xcube < -0.19 && ycube < 0.36 && ycube > 0.26) {
		ycube = 0.25;
		xcube = -0.1;
	}

	////Gornji levi cosak
	else if (xcube > -0.29 && xcube < -0.19 && ycube < 0.46 && ycube > 0.36)
		ycube = 0.25;

	//Gornja ivica
	else if (xcube > -0.19 && xcube < -0.09 && ycube < 0.46 && ycube > 0.36) {
		ycube = 0.35;
		xcube = -0.2;
	}
}
void CubeScramble::updateValueD(float& xcube, float& ycube) {
	//Rotacija prednje strane
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube < -0.24 && ycube > -0.34)
		xcube = 0.0;
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube < -0.24 && ycube > -0.34) {
		ycube = -0.35;
		xcube = 0.0;
	}
	//Gornja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube < -0.24 && ycube > -0.34)
		ycube = -0.45;
	//Desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube < -0.34 && ycube > -0.44) {
		ycube = -0.45;
		xcube = -0.1;
	}
	//Donja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube < -0.44 && ycube > -0.54)
		xcube = -0.2;
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube < -0.44 && ycube > -0.54) {
		ycube = -0.35;
		xcube = -0.2;
	}
	//Donja leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube < -0.44 && ycube > -0.54)
		ycube = -0.25;
	//Leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube < -0.34 && ycube > -0.44) {
		ycube = -0.25;
		xcube = -0.1;
	}

	//Ravna rotacija
	if (xcube + 0.34 > 0.75 && ycube > -0.15 && ycube < -0.05)
		xcube -= 1.05;
	else if (ycube > -0.16 && ycube < -0.06)
		xcube += 0.35;
}
void CubeScramble::updateValueDPrime(float& xcube, float& ycube) {
	if (xcube - 0.34 < -0.65 && ycube > -0.15 && ycube < -0.05)
		xcube += 1.05;
	else if (ycube > -0.15 && ycube < -0.05)
		xcube -= 0.35;

	//Rotacija prednje strane
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube < -0.24 && ycube > -0.34)
		ycube = -0.45;
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube < -0.24 && ycube > -0.34) {
		ycube = -0.35;
		xcube = -0.2;
	}
	//Gornja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube < -0.24 && ycube > -0.34)
		xcube = -0.2;
	//Desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube < -0.34 && ycube > -0.44) {
		ycube = -0.25;
		xcube = -0.1;
	}
	//Donja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube < -0.44 && ycube > -0.54)
		ycube = -0.25;
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube < -0.44 && ycube > -0.54) {
		ycube = -0.35;
		xcube = 0.0;
	}
	//Donja leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube < -0.44 && ycube > -0.54)
		xcube = 0.0;
	//Leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube < -0.34 && ycube > -0.44) {
		ycube = -0.45;
		xcube = -0.1;
	}
}
void CubeScramble::updateValueL(float& xcube, float& ycube) {
	//Zuti deo na plavu stranu
	if (ycube < -0.36 && ycube > -0.46 && xcube > -0.21 && xcube < -0.11) {
		ycube = 0.1;
		xcube = 0.70;
	}
	else if (ycube < -0.26 && ycube > -0.36 && xcube > -0.21 && xcube < -0.11) {
		ycube = 0.0;
		xcube = 0.70;
	}
	else if (ycube < -0.16 && ycube > -0.26 && xcube > -0.21 && xcube < -0.11) {
		ycube = -0.1;
		xcube = 0.70;
	}

	//Plava strana na beli deo 
	else if (ycube < 0.11 && ycube > 0.01 && xcube > 0.61 && xcube < 0.71) {
		ycube = 0.25;
		xcube = -0.2;
	}
	else if (ycube < 0.01 && ycube > -0.09 && xcube > 0.61 && xcube < 0.71) {
		ycube = 0.35;
		xcube = -0.2;
	}
	else if (ycube < -0.09 && ycube > -0.19 && xcube > 0.61 && xcube < 0.71) {
		ycube = 0.45;
		xcube = -0.2;
	}
	//generalno
	else if (ycube < 0.46 && ycube > -0.11 && xcube > -0.21 && xcube < -0.11) {

		ycube -= 0.35;
	}

	//Rotacija leve strane	
	//Gornja leva ivica
	if (ycube < 0.11 && ycube > 0.01 && xcube > -0.56 && xcube < -0.46) {
		xcube = -0.35;
	}
	//Leva ivica
	else if (ycube < 0.01 && ycube > -0.09 && xcube > -0.56 && xcube < -0.46) {
		ycube = 0.1;
		xcube = -0.45;
	}
	//Donja leva ivica
	else if (ycube < -0.09 && ycube > -0.19 && xcube > -0.56 && xcube < -0.46) {
		ycube = 0.1;
	}
	//Donja ivica
	else if (ycube < -0.09 && ycube > -0.19 && xcube > -0.46 && xcube < -0.36) {
		ycube = 0.0;
		xcube = -0.55;
	}
	//Donja desna ivica
	else if (ycube < -0.09 && ycube > -0.19 && xcube > -0.36 && xcube < -0.26) {
		xcube = -0.55;
	}
	//Desna ivica
	else if (ycube < 0.01 && ycube > -0.09 && xcube > -0.36 && xcube < -0.26) {
		ycube = -0.1;
		xcube = -0.45;
	}
	//Gornja desna ivica
	else if (ycube < 0.11 && ycube > 0.01 && xcube > -0.36 && xcube < -0.26) {
		ycube = -0.1;
	}
	//Gornja ivica
	else if (ycube < 0.11 && ycube > 0.01 && xcube > -0.46 && xcube < -0.36) {
		ycube = 0.0;
		xcube = -0.35;
	}

}
void CubeScramble::updateValueLPrime(float& xcube, float& ycube){
	//Plavi deo na zuti deo
	if (ycube < 0.11 && ycube > 0.01 && xcube > 0.61 && xcube < 0.71) {
		ycube = -0.45;
		xcube = -0.2;
	}
	else if (ycube < 0.01 && ycube > -0.09 && xcube > 0.61 && xcube < 0.71) {
		ycube = -0.35;
		xcube = -0.2;
	}
	else if (ycube < -0.09 && ycube > -0.19 && xcube > 0.61 && xcube < 0.71) {
		ycube = -0.25;
		xcube = -0.2;
	}

	////Beli deo na plavu stranu
	else if (ycube < 0.46 && ycube > 0.36 && xcube > -0.21 && xcube < -0.11) {
		ycube = -0.1;
		xcube = 0.70;
	}
	else if (ycube < 0.36 && ycube > 0.26 && xcube > -0.21 && xcube < -0.11) {
		ycube = 0.0;
		xcube = 0.70;
	}
	else if (ycube < 0.26 && ycube > 0.16 && xcube > -0.21 && xcube < -0.11) {
		ycube = 0.1;
		xcube = 0.70;
	}
	//generalno
	else if (ycube < 0.11 && ycube > -0.46 && xcube > -0.21 && xcube < -0.11) {
		ycube += 0.35;
	}

	//Rotacija leve strane	
	//Gornja leva ivica
	if (ycube < 0.11 && ycube > 0.01 && xcube > -0.56 && xcube < -0.46) {
		ycube = -0.1;
	}
	//Leva ivica
	else if (ycube < 0.01 && ycube > -0.09 && xcube > -0.56 && xcube < -0.46) {
		ycube = -0.1;
		xcube = -0.45;
	}
	//Donja leva ivica
	else if (ycube < -0.09 && ycube > -0.19 && xcube > -0.56 && xcube < -0.46) {
		xcube = -0.35;
	}
	//Donja ivica
	else if (ycube < -0.09 && ycube > -0.19 && xcube > -0.46 && xcube < -0.36) {
		ycube = 0.0;
		xcube = -0.35;
	}
	//Donja desna ivica
	else if (ycube < -0.09 && ycube > -0.19 && xcube > -0.36 && xcube < -0.26) {
		ycube = 0.1;
		xcube = -0.35;
	}
	//Desna ivica
	else if (ycube < 0.01 && ycube > -0.09 && xcube > -0.36 && xcube < -0.26) {
		ycube = 0.1;
		xcube = -0.45;
	}
	//Gornja desna ivica
	else if (ycube < 0.11 && ycube > 0.01 && xcube > -0.36 && xcube < -0.26) {
		xcube = -0.55;
		ycube = 0.1;
	}
	////Gornja ivica
	else if (ycube < 0.11 && ycube > 0.01 && xcube > -0.46 && xcube < -0.36) {
		ycube = 0.0;
		xcube = -0.55;
	}
}
void CubeScramble::updateValueF(float& xcube, float& ycube){
	//Rotacija prednje strane

	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube > 0.01 && ycube < 0.11)
		xcube = 0.0;
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.0;
		xcube = 0.0;
	}
	//Gornja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > 0.01 && ycube < 0.11)
		ycube = -0.1;
	//Desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.1;
		xcube = -0.1;
	}
	//Donja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.19 && ycube < -0.09)
		xcube = -0.2;
	////Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.0;
		xcube = -0.2;
	}
	//Donja leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.19 && ycube < -0.09)
		ycube = 0.1;

	//Leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.1;
		xcube = -0.1;
	}

	//Rotacija okoline
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube > 0.16 && ycube < 0.26) {
		ycube = 0.1;
		xcube = 0.15;
	}
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > 0.16 && ycube < 0.26) {
		ycube = 0.0;
		xcube = 0.15;
	}
	//Gornja desna ivica bele
	else if (xcube > -0.01 && xcube < 0.09 && ycube > 0.16 && ycube < 0.26) {
		ycube = -0.1;
		xcube = 0.15;
	}
	//Gornja desna ivica crvene
	else if (xcube > 0.11 && xcube < 0.21 && ycube > 0.01 && ycube < 0.11) {
		ycube = -0.25;
		xcube = 0.0;
	}
	//Desna ivica
	else if (xcube > 0.11 && xcube < 0.21 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.25;
		xcube = -0.1;
	}
	//Donja desna ivica crvene
	else if (xcube > 0.11 && xcube < 0.21 && ycube > -0.19 && ycube < -0.09) {
		ycube = -0.25;
		xcube = -0.2;
	}
	//Donja desna ivica zute
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.34 && ycube < -0.24) {
		ycube = -0.1;
		xcube = -0.35;
	}
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > -0.34 && ycube < -0.24) {
		ycube = 0.0;
		xcube = -0.35;
	}
	//Donja leva ivica zute
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.34 && ycube < -0.24) {
		ycube = 0.1;
		xcube = -0.35;
	}
	//Donja leva narandzaste
	else if (xcube > -0.36 && xcube < -0.26 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.25;
		xcube = -0.2;
	}
	//Leva ivica
	else if (xcube > -0.36 && xcube < -0.26 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.25;
		xcube = -0.1;
	}
	//Gornja leva ivica narandzaste
	else if (xcube > -0.36 && xcube < -0.26 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.25;
		xcube = 0.0;
	}
}
void CubeScramble::updateValueFPrime(float& xcube, float& ycube){
	//Rotacija prednje strane
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube > 0.01 && ycube < 0.11)
		ycube = -0.1;
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.00;
		xcube = -0.2;
	}
	//Gornja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > 0.01 && ycube < 0.11)
		xcube = -0.2;
	//Desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.1;
		xcube = -0.1;
	}
	//Donja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.19 && ycube < -0.09)
		ycube = 0.1;
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.0;
		xcube = 0.0;
	}
	//Donja leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.19 && ycube < -0.09)
		xcube = 0.0;

	//Leva ivica
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.1;
		xcube = -0.1;
	}

	//Rotacija okoline
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube > 0.16 && ycube < 0.26) {
		ycube = -0.1;
		xcube = -0.35;
	}
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > 0.16 && ycube < 0.26) {
		ycube = 0.0;
		xcube = -0.35;
	}
	//Gornja desna ivica bele
	else if (xcube > -0.01 && xcube < 0.09 && ycube > 0.16 && ycube < 0.26) {
		ycube = 0.1;
		xcube = -0.35;
	}
	//Gornja desna ivica crvene
	else if (xcube > 0.11 && xcube < 0.21 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.25;
		xcube = -0.2;
	}
	//Desna ivica
	else if (xcube > 0.11 && xcube < 0.21 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.25;
		xcube = -0.1;
	}
	//Donja desna ivica crvene
	else if (xcube > 0.11 && xcube < 0.21 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.25;
		xcube = 0.0;
	}
	//Donja desna ivica zute
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.34 && ycube < -0.24) {
		ycube = 0.1;
		xcube = 0.15;
	}
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > -0.34 && ycube < -0.24) {
		ycube = 0.0;
		xcube = 0.15;
	}
	//Donja leva ivica zute
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.34 && ycube < -0.24) {
		ycube = -0.1;
		xcube = 0.15;
	}
	//Donja leva narandzaste
	else if (xcube > -0.36 && xcube < -0.26 && ycube > -0.19 && ycube < -0.09) {
		ycube = -0.25;
		xcube = 0.0;
	}
	//Leva ivica
	else if (xcube > -0.36 && xcube < -0.26 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.25;
		xcube = -0.1;
	}
	//Gornja leva ivica narandzaste
	else if (xcube > -0.36 && xcube < -0.26 && ycube > 0.01 && ycube < 0.11) {
		ycube = -0.25;
		xcube = -0.2;
	}
}
void CubeScramble::updateValueB(float& xcube, float& ycube){
	//Rotacija zadnje strane
	//Gornja leva ivica
	if (xcube > 0.41 && xcube < 0.51 && ycube > 0.01 && ycube < 0.11)
		xcube = 0.70;
	//Gornja ivica
	else if (xcube > 0.51 && xcube < 0.61 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.0;
		xcube = 0.70;
	}
	//Gornja desna ivica
	else if (xcube > 0.61 && xcube < 0.71 && ycube > 0.01 && ycube < 0.11)
		ycube = -0.1;
	//Desna ivica
	else if (xcube > 0.61 && xcube < 0.71 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.1;
		xcube = 0.60;
	}
	//Donja desna ivica
	else if (xcube > 0.61 && xcube < 0.71 && ycube > -0.19 && ycube < -0.09)
		xcube = 0.50;
	//Donja ivica
	else if (xcube > 0.51 && xcube < 0.61 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.0;
		xcube = 0.50;
	}
	//Donja leva ivica
	else if (xcube > 0.41 && xcube < 0.51 && ycube > -0.19 && ycube < -0.09)
		ycube = 0.1;
	//Leva ivica
	else if (xcube > 0.41 && xcube < 0.51 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.1;
		xcube = 0.60;
	}
	//Rotacija okoline
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube > 0.36 && ycube < 0.46) {
		ycube = -0.1;
		xcube = -0.55;
	}
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > 0.36 && ycube < 0.46) {
		ycube = 0.0;
		xcube = -0.55;
	}
	//Gornja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > 0.36 && ycube < 0.46) {
		ycube = 0.1;
		xcube = -0.55;
	}
	//Gornja desna ivica crvene
	else if (xcube > 0.26 && xcube < 0.36 && ycube > 0.09 && ycube < 0.19) {
		ycube = 0.45;
		xcube = -0.2;
	}
	//Desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.01 && ycube < 0.09) {
		ycube = 0.45;
		xcube = -0.1;
	}
	//Donja desna ivica crvene
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.11 && ycube < -0.01) {
		ycube = 0.45;
		xcube = 0.0;
	}
	//Donja desna ivica zute
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.46 && ycube < -0.36) {
		ycube = 0.1;
		xcube = 0.35;
	}
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > -0.46 && ycube < -0.36) {
		ycube = 0.0;
		xcube = 0.35;
	}
	//Donja leva ivica zute
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.46 && ycube < -0.36) {
		ycube = -0.1;
		xcube = 0.35;
	}
	//Donja leva narandzaste
	else if (xcube > -0.56 && xcube < -0.46 && ycube > -0.11 && ycube < -0.01) {
		ycube = -0.45;
		xcube = 0.0;
	}
	//Leva ivica
	else if (xcube > -0.56 && xcube < -0.46 && ycube > -0.01 && ycube < 0.09) {
		ycube = -0.45;
		xcube = -0.1;
	}
	//Gornja leva ivica narandzaste
	else if (xcube > -0.56 && xcube < -0.46 && ycube > 0.09 && ycube < 0.19) {
		ycube = -0.45;
		xcube = -0.2;
	}
}
void CubeScramble::updateValueBPrime(float& xcube, float& ycube){
	//Rotacija zadnje strane
	//Gornja leva ivica
	if (xcube > 0.41 && xcube < 0.51 && ycube > 0.01 && ycube < 0.11)
		ycube = -0.1;
	//Gornja ivica
	else if (xcube > 0.51 && xcube < 0.61 && ycube > 0.01 && ycube < 0.11) {
		ycube = 0.0;
		xcube = 0.50;
	}
	//Gornja desna ivica
	else if (xcube > 0.61 && xcube < 0.71 && ycube > 0.01 && ycube < 0.11)
		xcube = 0.50;
	//Desna ivica
	else if (xcube > 0.61 && xcube < 0.71 && ycube > -0.09 && ycube < 0.01) {
		ycube = 0.1;
		xcube = 0.60;
	}
	//Donja desna ivica
	else if (xcube > 0.61 && xcube < 0.71 && ycube > -0.19 && ycube < -0.09)
		ycube = 0.1;
	//Donja ivica
	else if (xcube > 0.51 && xcube < 0.61 && ycube > -0.19 && ycube < -0.09) {
		ycube = 0.0;
		xcube = 0.70;
	}
	//Donja leva ivica
	else if (xcube > 0.41 && xcube < 0.51 && ycube > -0.19 && ycube < -0.09)
		xcube = 0.70;
	//Leva ivica
	else if (xcube > 0.41 && xcube < 0.51 && ycube > -0.09 && ycube < 0.01) {
		ycube = -0.1;
		xcube = 0.60;
	}
	//Rotacija okoline
	//Gornja leva ivica
	if (xcube > -0.21 && xcube < -0.11 && ycube > 0.36 && ycube < 0.46) {
		ycube = 0.1;
		xcube = 0.35;
	}
	//Gornja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > 0.36 && ycube < 0.46) {
		ycube = 0.0;
		xcube = 0.35;
	}
	//Gornja desna ivica
	else if (xcube > -0.01 && xcube < 0.09 && ycube > 0.36 && ycube < 0.46) {
		ycube = -0.1;
		xcube = 0.35;
	}
	//Gornja desna ivica crvene
	else if (xcube > 0.26 && xcube < 0.36 && ycube > 0.09 && ycube < 0.19) {
		ycube = -0.45;
		xcube = 0.0;
	}
	//Desna ivica
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.01 && ycube < 0.09) {
		ycube = -0.45;
		xcube = -0.1;
	}
	//Donja desna ivica crvene
	else if (xcube > 0.26 && xcube < 0.36 && ycube > -0.11 && ycube < -0.01) {
		ycube = -0.45;
		xcube = -0.2;
	}
	//Donja desna ivica zute
	else if (xcube > -0.01 && xcube < 0.09 && ycube > -0.46 && ycube < -0.36) {
		ycube = -0.1;
		xcube = -0.55;
	}
	//Donja ivica
	else if (xcube > -0.11 && xcube < -0.01 && ycube > -0.46 && ycube < -0.36) {
		ycube = 0.0;
		xcube = -0.55;
	}
	//Donja leva ivica zute
	else if (xcube > -0.21 && xcube < -0.11 && ycube > -0.46 && ycube < -0.36) {
		ycube = 0.1;
		xcube = -0.55;
	}
	//Donja leva narandzaste
	else if (xcube > -0.56 && xcube < -0.46 && ycube > -0.11 && ycube < -0.01) {
		ycube = 0.45;
		xcube = -0.2;
	}
	//Leva ivica
	else if (xcube > -0.56 && xcube < -0.46 && ycube > -0.01 && ycube < 0.09) {
		ycube = 0.45;
		xcube = -0.1;
	}
	//Gornja leva ivica narandzaste
	else if (xcube > -0.56 && xcube < -0.46 && ycube > 0.09 && ycube < 0.19) {
		ycube = 0.45;
		xcube = 0.0;
	}
}


