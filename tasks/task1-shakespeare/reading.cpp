#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    ifstream myfile("teste.txt");
    cout << "Opening file..." << endl;

    if (myfile.is_open()) {
        cout << "File opened." << endl;

        int love_count = 0;
        int hate_count = 0;

        while (getline(myfile, line)) {
            cout << line << '\n';

            for (size_t i = 0; i + 3 < line.size(); i++) {
                if (line.compare(i, 4, "love") == 0 && (i + 4 >= line.size() || !isalpha(line[i + 4]))) {
                    love_count++;
                } else if (line.compare(i, 4, "hate") == 0 && (i + 4 >= line.size() || !isalpha(line[i + 4]))) {
                    hate_count++;
                }
            }
        }

        cout << "Total 'love' count: " << love_count << '\n';
        cout << "Total 'hate' count: " << hate_count << '\n';

        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}
