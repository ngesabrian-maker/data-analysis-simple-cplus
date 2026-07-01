#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class sample {
public:
    double numbers[50];
    int frequency; // Changed to int since it counts items
    double sumFn();
    double meanFn();
    double medianFn();
};

sample item;

// Function returns a double so the mean function can use it
double sample::sumFn() {
    double sum = 0.0;
    for (int i = 0; i < frequency; i++) {
        sum += numbers[i]; // Fixed the =+ typo to +=
    }
    return sum;
}

// Function calculates and prints the arithmetic mean
double sample::meanFn() {
    if (frequency == 0) {
        cout << "Cannot divide by zero." << endl;
        return 0.0;
    }
    double sum = sumFn();
    double mean = sum / frequency;
    cout << "The mean of the numbers is: " << mean << endl;
    return mean;
}

//function to arrange and find the median of a number
double sample::medianFn() {
    if (frequency == 0) {
        cout << "No data to find median." << endl;
        return 0.0;
    }

    // Sort only the active elements in the array
    sort(numbers, numbers + frequency);

    double median;
    if (frequency % 2 != 0) {
        // Odd number of elements: take the middle one
        median = numbers[frequency / 2];
    } else {
        // Even number of elements: average the two middle ones
        median = (numbers[(frequency / 2) - 1] + numbers[frequency / 2]) / 2.0;
    }

    cout << "The median of the numbers is: " << median << endl;
    return median;
}

int main() {

    cout << "Input the frequency (max 50): " << endl;
    cin >> item.frequency;

    // Guard against array overflow
    if (item.frequency > 50 || item.frequency <= 0) {
        cout << "Invalid frequency size." << endl;
        return 1;
    }

    cout << "Input " << item.frequency << " numbers:" << endl;
    for (int i = 0; i < item.frequency; i++) {
        cin >> item.numbers[i];
    }

    cout << "\nYour numbers are:" << endl;
    for (int i = 0; i < item.frequency; i++) {
        cout << item.numbers[i] << " ";
    }
    cout << endl;

    // Pass the array name 'item.numbers' without brackets
    double totalSum = item.sumFn();
    cout << "The sum of the numbers is: " << totalSum << endl;

    // Call the mean function using the total sum
    double mean2 = item.meanFn();
    double median2 = item.medianFn();

    ofstream stat("data.csv");
    if (stat.is_open()){
            stat<<"NUMBERS\n";
        for (int i = 0; i < item.frequency; i++) {
        stat<< item.numbers[i]<<"\n";

        }
        stat<<"average,"<<mean2<<"\n";
        stat<<"total,"<<totalSum<<"\n";
        stat.close();
        cout<<"file created succesfully"<<endl;
    }
    else{
         cerr<<"error: fail to create"<<endl;
    }
    return 0;
}
