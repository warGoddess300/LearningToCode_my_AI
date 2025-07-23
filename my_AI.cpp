/*I wish i code my personal AI on my phone and my computer
*
*c++ chatbot but from github copilot
* i'm an ultra beginner, so, i asked this code to the AI to learn how to code
* a c++ AI
*/


#include <iostream>

/* `<fstream>` C++ header (read, write, changes files on the hard disk).

- `<fstream>` means "file stream" (flux de fichiers).
- Il fournit trois classes principales :
  - `ifstream` (input file stream) : pour lire un fichier.
  - `ofstream` (output file stream) : pour écrire dans un fichier.
  - `fstream` : pour lire et écrire dans un fichier.

In the code, `ifstream reads file("connaissances.txt");` open the folder connaissances.txt (read), to load knowings from the chatbot.

En résumé :
- `<fstream>` : can manipulate C++ files.
- `ifstream` : reads what is in a file.

*/


#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> connaissances;
    string ligne, question, reponse;

    /*
    
    ifstream fichierLecture("connaissances.txt"); ouvre le fichier connaissances.txt en lecture, pour que le programme puisse charger les connaissances du chatbot.

    En résumé :
    - `<fstream>` : pour manipuler les fichiers en C++.
    - `ifstream` : pour lire le contenu d’un fichier.
    */

    ifstream fichierLecture("connaissances.txt");
    // Charger les connaissances depuis le fichier
    while (getline(fichierLecture, ligne)) {

/*

<fstream> : pour manipuler les fichiers en C++.
ifstream : pour lire le contenu d’un fichier.
    
    */

    
    ifstream fichierLecture("connaissances.txt");
    // Charger les connaissances depuis le fichier
    while (getline(fichierLecture, ligne)) {
        size_t sep = ligne.find('|');
        if (sep != string::npos) {
            question = ligne.substr(0, sep);
            reponse = ligne.substr(sep + 1);
            connaissances[question] = reponse;
        }
    }
    fichierLecture.close();

    string userInput;
    cout << "Bienvenue ! Je suis un chatbot. Tapez 'quit' pour quitter.\n";
    while (true) {
        cout << "Vous: ";
        getline(cin, userInput);
        if (userInput == "quit") {
            cout << "Chatbot: Au revoir !" << endl;
            break;
        } else if (userInput == "bonjour") {
            cout << "Chatbot: Bonjour ! Comment puis-je vous aider ?" << endl;
        } else if (userInput == "comment ça va") {
            cout << "Chatbot: Je vais bien, merci ! Et vous ?" << endl;
        } else if (userInput == "quel est ton nom") {
            cout << "Chatbot: Je suis un simple chatbot en C++." << endl;
        } else if (connaissances.find(userInput) != connaissances.end()) {
            cout << "Chatbot: " << connaissances[userInput] << endl;
        } else {
            cout << "Chatbot: Je ne connais pas la réponse. Quelle devrait être ma réponse ?" << endl;
            cout << "Vous (nouvelle réponse): ";
            getline(cin, reponse);
            connaissances[userInput] = reponse;
            ofstream fichierEcriture("connaissances.txt", ios::app);
            fichierEcriture << userInput << "|" << reponse << endl;
            fichierEcriture.close();
            cout << "Chatbot: Merci, j'ai appris une nouvelle réponse !" << endl;
        }
    }
    return 0;
}
}
