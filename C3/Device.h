#pragma once

#include <vector>
#include <string>

#define g 9.81
#define numberPack 10

typedef struct omega {
	omega() {
		omega_x = 0.0;
		omega_y = 0.0;
		omega_z = 0.0;
	}
	double omega_x,
		omega_y,
		omega_z;
} omega;

typedef struct pack_input {
	pack_input() {
		t = 0.0;
		fi_x = 0.0;
		fi_y = 0.0;
		fi_z = 0.0;
		accel_x = 0.0;
		accel_y = 0.0;
		accel_z = 0.0;
		v_x = 0.0;
	}
	double t,
		fi_x,
		fi_y,
		fi_z,
		accel_x,
		accel_y,
		accel_z,
		v_x;
} pack_input;

typedef struct pack_output {
	pack_output() {
		t = 0.0;
		x = 0.0;
		y = 0.0;
		z = 0.0;
		v_x = 0.0;
		v_y = 0.0;
		v_z = 0.0;
	}
	double t,
		x,
		y,
		z,
		v_x,
		v_y,
		v_z;
} pack_output;

using namespace std;

class Device
{
public:
	Device();
	static void pathRestoration(string inputFile, string outputFile);
	static void algorithmPathRestoration(vector<pack_input> &input, vector<pack_output> &output, vector<omega> omegaPack, pack_output &state, pack_input &state_input);
	static void writePackToFile(ofstream &out, pack_output &packOut);
	static void readPackOfFile(ifstream &inp, pack_input &packInp);
	static void backRotate(pack_input &inputNext, pack_input &inputFirst, pack_output &output);
	static vector<pack_input> smoothing(vector<pack_input> &input);
	static vector<omega> smoothing(vector<omega> &input);
	static void subtractionCentrifugalForce(pack_output &state, pack_input &input, omega stateOmega, double deltaTime);
	~Device();
};

