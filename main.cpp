#include <vector>
#include <iostream>
#include <chrono>
#include "vectorc.h"

/* 
	VECTORS GENERATION			
*/
Vector_template(int);
Vector_template(float);
Vector_template(double);

/* 
  TEST
*/
int main(int argc, char **argv) {
	int val = 10;
	int mem = 10;
	
  // Init
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	Vector_init(vec, int);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span =std::chrono:: duration_cast<std::chrono::duration<double> >(t2 - t1);
	std::cout << "-> C vector init time: " << time_span.count() << " seconds.";
  std::cout << std::endl;

	if(argc == 3) {
		val = atoi(argv[1]);
		mem = atoi(argv[2]);
	}
	
	// Reserve
	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
	Vector_reserve(vec, mem); // Optional, reserve custom space
	
	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span1 =std::chrono:: duration_cast<std::chrono::duration<double> >(t4 - t3);
	std::cout << "-> C vector reserve time: " << time_span1.count() << " seconds.";
    std::cout << std::endl;
	
	// Push back
	std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < val; i++) {
		Vector_push(vec, i);
	}
	std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span2 =std::chrono:: duration_cast<std::chrono::duration<double> >(t6 - t5);
	std::cout << "-> C vector push_back time: " << time_span2.count() << " seconds.";
    std::cout << std::endl;
	
	// Free
	std::chrono::high_resolution_clock::time_point t7 = std::chrono::high_resolution_clock::now();
	Vector_clear(vec);
	std::chrono::high_resolution_clock::time_point t8 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span3 =std::chrono:: duration_cast<std::chrono::duration<double> >(t8 - t7);
	std::cout << "-> C vector clear time: " << time_span3.count() << " seconds.";
    std::cout << std::endl;
	
	
	// STD VECTOR
	int valCPP = 10;
	int memCpp = 10;
	if(argc == 3) {
		valCPP = atoi(argv[1]);
		memCpp = atoi(argv[2]);
	}
	std::chrono::high_resolution_clock::time_point t9 = std::chrono::high_resolution_clock::now();
	std::vector<int> vec1;
	std::chrono::high_resolution_clock::time_point t10 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_spanCPP =std::chrono:: duration_cast<std::chrono::duration<double> >(t10 - t9);
	std::cout << "-> std::vector init time: " << time_spanCPP.count() << " seconds.";
    std::cout << std::endl;
	
	std::chrono::high_resolution_clock::time_point t11 = std::chrono::high_resolution_clock::now();
	vec1.reserve(memCpp);
	std::chrono::high_resolution_clock::time_point t12 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_spanCPP1 =std::chrono:: duration_cast<std::chrono::duration<double> >(t12 - t11);
	std::cout << "-> std::vector reserve time: " << time_spanCPP1.count() << " seconds.";
    std::cout << std::endl;
	
	std::chrono::high_resolution_clock::time_point t13 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < valCPP; i++){
		vec1.push_back(i);
	}

	std::chrono::high_resolution_clock::time_point t14 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_spanCPP2 =std::chrono:: duration_cast<std::chrono::duration<double> >(t14 - t13);
	std::cout << "-> std::vector push back time: " << time_spanCPP2.count() << " seconds.";
    std::cout << std::endl;
	
	std::chrono::high_resolution_clock::time_point t15 = std::chrono::high_resolution_clock::now();
	vec1.clear();
	std::chrono::high_resolution_clock::time_point t16 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_spanCPP3 =std::chrono:: duration_cast<std::chrono::duration<double> >(t16 - t15);
	std::cout << "-> std::vector clear time: " << time_spanCPP3.count() << " seconds.";
    std::cout << std::endl;

	return 0;
}