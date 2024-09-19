#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "sorting_algorithms.h"
#include "linked_list.h"
#include "graphing.h"

// Función para generar datos de prueba
std::vector<int> generateData(int N, const std::string& caseType) {
    std::vector<int> data(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    if (caseType == "best") {
        for (int i = 0; i < N; ++i) {
            data[i] = i;
        }
    } else if (caseType == "worst") {
        for (int i = 0; i < N; ++i) {
            data[i] = N - i;
        }
    } else { // average case
        for (int i = 0; i < N; ++i) {
            data[i] = dis(gen);
        }
    }

    return data;
}

// Función para medir el tiempo de ejecución de un algoritmo
template <typename Func>
double measureExecutionTime(Func func, std::vector<int>& data) {
    auto start = std::chrono::high_resolution_clock::now();
    func(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

int main() {
    std::vector<int> sizes = {100, 1000, 5000, 10000}; // Diferentes valores de N
    std::vector<std::string> cases = {"best", "average", "worst"};

    for (const auto& caseType : cases) {
        std::cout << "Case: " << caseType << std::endl;
        for (const auto& size : sizes) {
            std::vector<int> data = generateData(size, caseType);
            double timeTaken = measureExecutionTime(bubbleSort, data);
            std::cout << "BubbleSort with N=" << size << " took " << timeTaken << " seconds" << std::endl;
        }
    }

    // Graficar resultados
    drawGraph();

    return 0;
}
