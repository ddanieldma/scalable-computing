#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int countLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return -1;
    }

    int lineCount = 0;
    std::string line;

    while (std::getline(file, line)) {
        ++lineCount;
    }

    return lineCount;
}

vector<thread> createThreads(int numTh, int* arr) {
    // Vetor de threads
    vector<thread> threads;

    // Criando e inicializando threads
    for (int i = 0; i < numTh; i++) {
        threads.push_back(thread(sumTo100, arr, i));
    }

    cout << "Threads executando concorrentemente..." << endl;

    return threads;
}

void joinThreads(vector<thread>& threads) {
    // Juntando todas as threads
    for (auto& th : threads) {
        th.join();
    }

    cout << "Threads finalizadas" << endl;
}

// Criando vetor com arquivo
vector<string> readFileToVector(){
    
}

int main () {
    // Number of threads
    int numTh = 10;
    
    // Criando array para armazenar somas das threads
    int* arr = new int[numTh];

    // Inicializando array
    for (int i = 0; i < numTh; i++){
        arr[i] = 0;
    }

    vector<thread> threads= createThreads(numTh, arr);
    joinThreads(threads)    ;

    cout << "Printando array" << endl;
    printArray(arr, numTh);

    delete[] arr;

    return 0;
}