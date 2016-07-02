
#include <iostream>
#include <string>
// Allow us to work with files
#include <fstream>

using namespace std;

int main() {

	// ---------- FILE I/O ----------
	// We can read and write to files using text or machine readable binary

	string steveQuote = "A day without sunshine is like, you know, night";

	// Create an output filestream and if the file doesn't exist create it
	ofstream writer("stevequote.txt");

	// Verify that the file stream object was created
	if (!writer) {

		cout << "Error opening file" << endl;

		// Signal that an error occurred
		return -1;

	}
	else {

		// Write the text to the file
		writer << steveQuote << endl;

		// Close the file
		writer.close();

	}

	// Open a stream to append to whats there with ios::app
	// ios::binary : Treat the file as binary
	// ios::in : Open a file to read input
	// ios::trunc : Default
	// ios::out : Open a file to write output
	ofstream writer2("stevequote.txt", ios::app);

	if (!writer2) {

		cout << "Error opening file" << endl;

		// Signal that an error occurred
		return -1;

	}
	else {

		writer2 << "\n- Steve Martin" << endl;
		writer2.close();

	}

	char letter;

	// Read characters from a file using an input file stream
	ifstream reader("stevequote.txt");

	if (!reader) {

		cout << "Error opening file" << endl;
		return -1;

	}
	else {

		// Read each character from the stream until end of file
		for (int i = 0; !reader.eof(); i++) {

			// Get the next letter and output it
			reader.get(letter);
			cout << letter;

		}

		cout << endl;
		reader.close();
	}

	return 0;
}