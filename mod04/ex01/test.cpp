#include <iostream>
#include <iomanip>
#include <ctime>

const int NUM_OBJECTS = 100; // total number of objects to instantiate
const int NUM_DOGS = NUM_OBJECTS / 2; // number of dog objects
const int NUM_CATS = NUM_OBJECTS - NUM_DOGS; // number of cat objects

void update_progress_bar(int progress) {
    std::cout << "\r[";
    int pos = 0;
    for (int i = 0; i < 50; ++i) {
        if (pos < progress) {
            std::cout << "=";
        } else {
            std::cout << ".";
        }
        ++pos;
    }
    std::cout << "] " << std::fixed << std::setprecision(2) << static_cast<double>(progress) / NUM_OBJECTS * 100.0 << "%";
    std::cout.flush();
    clock_t start_time = clock();    // measure start time before delay
    while (clock() < start_time + 2000)   // pause for 10ms
    {
        // do nothing
    }
}

int main() {
    int num_dogs_completed = 0;
    int num_cats_completed = 0;

    std::cout << "Starting instantiation of " << NUM_OBJECTS << " objects..." << std::endl;

    for (int i = 0; i < NUM_OBJECTS; ++i) {
        if (i % 2 == 0) {
            // instantiate a dog object
            ++num_dogs_completed;
            update_progress_bar(num_dogs_completed);
        } else {
            // instantiate a cat object
            ++num_cats_completed;
            update_progress_bar(num_cats_completed);
        }
        // simulate some work being done on each object
        // ...
    }

    std::cout << std::endl << "Done!" << std::endl;

    return 0;
}
