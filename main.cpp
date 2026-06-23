#include <iostream>
#include <fstream>

using namespace std;

class sample {
public:
    double numbers[50];
    int frequency; // Changed to int since it counts items
};

sample item;

// Function returns a double so the mean function can use it
double sumFn(double numbers[], int frequency) {
    double sum = 0.0;
    for (int i = 0; i < frequency; i++) {
        sum += numbers[i]; // Fixed the =+ typo to +=
    }
    return sum;
}

// Function calculates and prints the arithmetic mean
double meanFn(double sum, int frequency) {
    if (frequency == 0) {
        cout << "Cannot divide by zero." << endl;
        return 0.0;
    }
    double mean = sum / frequency;
    cout << "The mean of the numbers is: " << mean << endl;
    return mean;
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
    double totalSum = sumFn(item.numbers, item.frequency);
    cout << "The sum of the numbers is: " << totalSum << endl;

    // Call the mean function using the total sum
    double mean2 = meanFn(totalSum, item.frequency);

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
