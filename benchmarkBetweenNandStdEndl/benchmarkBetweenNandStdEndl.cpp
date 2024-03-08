// INCLUDES //
#include <iostream>
#include <fstream> // For files
#include <chrono> // For time convertation and timer
#include <cstdio> // For std::remove

using namespace std::chrono;

int main()
{
    const uint32_t iterations = 1000000; // change amount of iterations from 0 to 2^32 (4,294,967,296)

    // Benchmark of \n //
    auto start = high_resolution_clock::now(); // CHRONO
    std::ofstream file1("n");

    if (file1.is_open()) {
        for (uint32_t i = 0; i < iterations; i++) {
            file1 << "This is a test line using \"\\n\" \n";
        }

        file1.close();
    }

    auto end = high_resolution_clock::now(); // CHRONO

    // TIME CONVERTATION FOR \n //
    auto convertDurationToMicroSecondsN = duration_cast<microseconds>(end - start); // CHRONO
    auto convertDurationToMiliSecondsN = duration_cast<milliseconds>(end - start); // CHRONO

    // Benchmark of std::endl //
    start = high_resolution_clock::now(); // CHRONO
    std::ofstream file2("stdendl");

    if (file2.is_open()) {
        for (uint32_t i = 0; i < iterations; i++) {
            file2 << "This is a test line using std::endl" << std::endl;
        }

        file2.close();
    }

    end = high_resolution_clock::now(); // CHRONO

    // TIME CONVERTATION FOR std::endl //
    auto convertDurationToMicroSecondsS = duration_cast<microseconds>(end - start); // CHRONO
    auto convertDurationToMiliSecondsS = duration_cast<milliseconds>(end - start); // CHRONO

    // Delete files after benchmark //
    std::remove("n");
    std::remove("stdendl");

    // OUTPUT INFORMATION IN SEPARATE FILE //
    std::ofstream outputFile("Result.txt");

    outputFile << "Time taken by \"\\n\" to complete " << iterations << " iterations: "
        << convertDurationToMicroSecondsN.count() << " microseconds or "
        << convertDurationToMiliSecondsN.count() << " miliseconds\n";

    outputFile << "Time taken by std::endl to complete " << iterations << " iterations: "
        << convertDurationToMicroSecondsS.count() << " microseconds or "
        << convertDurationToMiliSecondsS.count() << " miliseconds\n";

}
