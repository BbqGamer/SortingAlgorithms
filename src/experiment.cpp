#include "algorithms.h"
#include "utils.h"
#include "includes.h"

using namespace std;

#define STEP 500
#define TIMEOUT_SECONDS 1
#define TIMEOUT_REPETITIONS 5

void experiment(std::vector<sortingFunction> algs, std::vector<std::string> names, std::vector<int> limits, std::vector<char> types, std::string filename) {

    ofstream f;
    f.open(filename);
    f << "algorithm,type,n,time\n";

    int timeouts = 0;

    for(int i = 0; i < algs.size(); i++) {
        for(auto type: types) {
            for(int n = STEP; n < limits[i]; n += STEP) {
                int* A = randomArray(n, 0, 100, type);
                float time = measureAlg(algs[i], A, n);
                f << names[i] << "," << type << "," << n << "," << time << endl;
                delete[] A;

                if(time > TIMEOUT_SECONDS) {
                    timeouts += 1;
                    if (timeouts >= TIMEOUT_REPETITIONS) {
                        break;
                    }
                } else {
                    timeouts = 0;
                }
            }
        }
    }

    f.close();
}

int main() {
    std::vector<sortingFunction> algs1 = {BS, HS, CS, ShS};
    std::vector<std::string> names1 = {"BS", "HS", "CS", "ShS"};
    std::vector<int> limits1 = {15000, 500000, 500000, 500000};
    std::vector<char> types1 = {'r'};
    std::string filename1 = "./output/experiment1.csv";
    experiment(algs1, names1, limits1, types1, filename1);

    std::vector<sortingFunction> algs2 = {HS, QS, MS};
    std::vector<std::string> names2 = {"HS", "QS", "MS"};
    std::vector<int> limits2 = {500000, 500000, 500000};
    std::vector<char> types2 = {'r', 'c', 'i', 'd', 'A', 'V'};
    std::string filename2 = "./output/experiment2.csv";
    experiment(algs2, names2, limits2, types2, filename2);
    
}