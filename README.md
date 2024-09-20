# 🔒 Password Input and Validation Program
This C program provides a simple command-line interface for password input and validation. It prompts the user to enter a password, displaying asterisks (*) for each character entered, ensuring that the actual password remains hidden. The program then compares the entered password against a stored password in a text file.

### Features
* Secure Input: Utilizes _getch() to capture user input without displaying it on the screen.
* Basic Password Management: Reads a saved password from password.txt and compares it with user input.
* User-Friendly Interface: Provides feedback on login success or failure.

### Usage
* Compile the Program: Use a suitable C compiler (e.g., GCC).
* Create a Password File: Ensure password.txt contains the password to be matched.
* Run the Program: Execute the compiled binary in a terminal.
  
### Important Notes
* The program uses the <conio.h> library, which is specific to Windows environments. It may not compile on Unix/Linux systems without modifications.
* The current implementation utilizes a goto statement for retrying password input. Consider replacing it with a more structured looping mechanism for improved readability and maintenance.

Feel free to contribute or suggest enhancements!
