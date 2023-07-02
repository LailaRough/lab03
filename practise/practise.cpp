#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char GIST_CHAR = '*';
const char GIST_SPACE = ' ';
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double> getNumbersForBins(size_t numbersCount);
vector<size_t> binFull(vector<double> numbers, size_t binCount);
void findMinMax(vector<double> numbers, double& min, double& max);
void showHistogram(vector<size_t> bins, size_t mx);
size_t findMaxBinCount(vector<size_t> bins);

int main() {
    size_t numbersCount;
    cerr << "Enter numbers count: ";
    cin >> numbersCount;

    vector<double> numbers;
    cerr << "Enter numbers: ";
    numbers = getNumbersForBins(numbersCount);

    size_t binCount;
    cerr << "Enter bins count: ";
    cin >> binCount;
    cerr << endl;
    vector<size_t> bins = binFull(numbers, binCount);
    size_t maxBinCount = findMaxBinCount(bins);//корзина  с большим количеством элементов
    showHistogram(bins, maxBinCount);
    //cmdOutput(bins, maxBinCount);
}

//+
vector<double> getNumbersForBins(size_t numbersCount) {
    vector<double> numbers(numbersCount);
    for (int i = 0; i < numbersCount; i++) {
        cin >> numbers[i];
    }
    return numbers;
}
//+
vector<size_t> binFull(vector<double> numbers, size_t binCount) {
    vector<size_t> bins(binCount);
    double min = numbers[0];
    double max = numbers[0];
    findMinMax(numbers, min, max);
    double step = (max - min) / binCount;

    for (auto x : numbers) {
        bool found = false;
        for (size_t i = 0; (i < binCount - 1) && !found; i++) {
            auto lo = min + i * step;
            auto hi = min + (i + 1) * step;
            if ((lo <= x) && (x < hi)) {
                bins[i]++;
                found = true;
            }
        }
        if (!found) {
            bins[binCount - 1]++;
        }
    }
    return bins;
}

void findMinMax(vector<double> numbers, double& min, double& max) {
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        else if (numbers[i] > max) {
            max = numbers[i];
        }
    }
}


///size_t height = MAX_GIST_WIDTH * (static_cast<double>(col) / mx);

//+
size_t findMaxBinCount(vector<size_t> bins) {
    size_t mx = 0;
    for (size_t item : bins) {
        if (item > mx) {
            mx = item;
        }
    }
    return mx;

}

void showHistogram(vector<size_t> bins, size_t mx) {
    /* проба с масштабированием
    for (size_t row = mx; row > 0; row--) {
        for (size_t col : bins) {

            size_t height = col;
            const bool scaling_needed = mx > MAX_ASTERISK; 
            if (scaling_needed) {
                const double scaling_factor = (double)MAX_ASTERISK / mx;
                height = (size_t)(col * scaling_factor);
            }
            if (col >= row) {
                for (size_t i = 0; i < height; i++) {
                    cerr << GIST_CHAR;
                }
            }

            else {
                for (size_t i = 0; i < height; i++) {
                    cerr << GIST_SPACE;
                }
            }
        }
            cerr << endl;
    }
    */
    //без масштабирования
    for (size_t row = mx; row > 0; row--) {
        for (size_t col : bins) {

            if (col >= row) {
                    cerr << GIST_CHAR;
            }

            else {
                    cerr << GIST_SPACE;
            }
        }
        cerr << endl;
    }
}


