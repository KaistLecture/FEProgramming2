#pragma once

#define OPT_N		1
#define VOLATILITY	0.2
#define RISKFREE	0.02
#define RAND_N		1000000


void MonteCarlo(
	float *h_CallResult,
	float *h_CallConfidence,
	float *S,
	float *X,
	float *T
	);