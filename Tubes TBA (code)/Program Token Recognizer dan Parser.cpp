#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

// Definisi state pada finite automata
enum StateFA {
    START,
    q1, q2, q3,  // Kami
    q4, q5,      // Ibu
    q6, q7, q8,  // Budi
    q9, q10,     // Aku
    q11, q12,    // Dia
    q13, q14, q15, q16, q17, q18, // Bermain
    q19, q20, q21, q22, q23, q24, // Belajar
    q25, q26, q27, q28, q29, q30, q31, // Membaca
    q32, q33, q34, q35, // Minum
    q36, q37, q38, q39, // Makan
    q40, q41, q42, // Bola
    q43, q44, q45, q46, q47, // Fisika
    q48, q49, q50, // Buku
    q51, q52, // Air
    q53, q54, q55, // Soto
    q56, q57, q58, // Di_
    q59, q60, q61, q62, // taman
    q63, q64, q65, q66, // kelas
    q67, q68, q69, q70, // rumah
    q71, q72, q73, q74, // dapur
    q75, q76, q77, q78, // kantin
    ACCEPT,
    REJECT
};

enum StatePDA {
    IS,
    S_FOUND,
    P_FOUND,
    O_FOUND,
    K_FOUND,
    INVALID
};

// Fungsi transisi state untuk subjek
StateFA transitionSubjek(StateFA current, char input) {
    switch (current) {
        case START:
            if (input == 'K' || input == 'k') return q1;
            if (input == 'I' || input == 'i') return q4;
            if (input == 'B' || input == 'b') return q6;
            if (input == 'A' || input == 'a') return q9;
            if (input == 'D' || input == 'd') return q11;
            break;
        case q1:  // Kami
            if (input == 'A' || input == 'a') return q2;
            break;
        case q2:
            if (input == 'M' || input == 'm') return q3;
            break;
        case q3:
            if (input == 'I' || input == 'i') return ACCEPT;
            break;
        case q4:  // Ibu
            if (input == 'B' || input == 'b') return q5;
            break;
        case q5:
            if (input == 'U' || input == 'u') return ACCEPT;
            break;
        case q6:  // Budi
            if (input == 'U' || input == 'u') return q7;
            break;
        case q7:
            if (input == 'D' || input == 'd') return q8;
            break;
        case q8:
            if (input == 'I' || input == 'i') return ACCEPT;
            break;
        case q9:  // Aku
            if (input == 'K' || input == 'k') return q10;
            break;
        case q10:
            if (input == 'U' || input == 'u') return ACCEPT;
            break;
        case q11:  // Dia
            if (input == 'I' || input == 'i') return q12;
            break;
        case q12:
            if (input == 'A' || input == 'a') return ACCEPT;
            break;
        default:
            return REJECT;
    }
    return REJECT;
}

// Fungsi transisi state untuk predikat
StateFA transitionPredikat(StateFA current, char input) {
    switch (current) {
        case START:
            if (input == 'B' || input == 'b') return q13;
            if (input == 'M' || input == 'm') return q25;
            break;
        case q13:  // Bermain / Belajar
            if (input == 'E' || input == 'e') return q14;
            break;

        case q14:
            if (input == 'R' || input == 'r') return q15;
            if (input == 'L' || input == 'l') return q19;  // Belajar
            break;
        case q15:
            if (input == 'M' || input == 'm') return q16;  // Bermain
            break;
        case q16:
            if (input == 'A' || input == 'a') return q17;
            break;
        case q17:
            if (input == 'I' || input == 'i') return q18;
            break;
        case q18:
            if (input == 'N' || input == 'n') return ACCEPT;
            break;
        case q19:
            if (input == 'A' || input == 'a') return q20;
            break;
        case q20:
            if (input == 'J' || input == 'j') return q21;
            break;
        case q21:
            if (input == 'A' || input == 'a') return q22;
            break;
        case q22:
            if (input == 'R' || input == 'r') return ACCEPT;
            break;
        case q25:  // Membaca / Minum / Makan
            if (input == 'E' || input == 'e') return q26;
            if (input == 'I' || input == 'i') return q32;  // Minum
            if (input == 'A' || input == 'a') return q36;  // Makan
            break;
        case q26:
            if (input == 'M' || input == 'm') return q27;
            break;
        case q27:
            if (input == 'B' || input == 'b') return q28;
            break;
        case q28:
            if (input == 'A' || input == 'a') return q29;
            break;
        case q29:
            if (input == 'C' || input == 'c') return q30;
            break;
        case q30:
            if (input == 'A' || input == 'a') return ACCEPT;
            break;
        case q32:  // Minum
            if (input == 'N' || input == 'n') return q33;
            break;
        case q33:
            if (input == 'U' || input == 'u') return q34;
            break;
        case q34:
            if (input == 'M' || input == 'm') return ACCEPT;
            break;
        case q36:  // Makan
            if (input == 'K' || input == 'k') return q37;
            break;
        case q37:
            if (input == 'A' || input == 'a') return q38;
            break;
        case q38:
            if (input == 'N' || input == 'n') return ACCEPT;
            break;
        default:
            return REJECT;
    }
    return REJECT;
}

// Fungsi transisi state untuk objek
StateFA transitionObjek(StateFA current, char input) {
    switch (current) {
        case START:
            if (input == 'B' || input == 'b') return q40;  // Bola / Buku
            if (input == 'F' || input == 'f') return q43;  // Fisika
            if (input == 'A' || input == 'a') return q51;  // Air
            if (input == 'S' || input == 's') return q53;  // Soto
            break;
        case q40:  // Bola / Buku
            if (input == 'O' || input == 'o') return q41;
            if (input == 'U' || input == 'u') return q48;
            break;
        case q41:
            if (input == 'L' || input == 'l') return q42;
            break;
        case q42:
            if (input == 'A' || input == 'a') return ACCEPT;
            break;
        case q43:  // Fisika
            if (input == 'I' || input == 'i') return q44;
            break;
        case q44:
            if (input == 'S' || input == 's') return q45;
            break;
        case q45:
            if (input == 'I' || input == 'i') return q46;
            break;
        case q46:
            if (input == 'K' || input == 'k') return q47;
            break;
        case q47:
            if (input == 'A' || input == 'a') return ACCEPT;
            break;
        case q48:  // Buku
            if (input == 'K' || input == 'k') return q49;
            break;
        case q49:
            if (input == 'U' || input == 'u') return ACCEPT;
            break;
        case q51:  // Air
            if (input == 'I' || input == 'i') return q52;
            break;
        case q52:
            if (input == 'R' || input == 'r') return ACCEPT;
            break;
        case q53:  // Soto
            if (input == 'O' || input == 'o') return q54;
            break;
        case q54:
            if (input == 'T' || input == 't') return q55;
            break;
        case q55:
            if (input == 'O' || input == 'o') return ACCEPT;
            break;
        default:
            return REJECT;
    }
    return REJECT;
}

// Fungsi transisi state untuk keterangan
StateFA transitionKeterangan(StateFA current, char input) {
    switch (current) {
        case START:
            if (input == 'D' || input == 'd') return q56;
            break;
        case q56:  // di_
            if (input == 'I' || input == 'i') return q57;
            break;
        case q57:  // di_
            if (input == '_') return q58;
            break;
        case q58:
            if (input == 'T' || input == 't') return q59;  // di_taman
            if (input == 'K' || input == 'k') return q63;  // di_kelas || di_kantin
            if (input == 'R' || input == 'r') return q67;  // di_rumah
            if (input == 'D' || input == 'd') return q71;  // di_dapur
            break;
        case q59:  // taman
            if (input == 'A' || input == 'a') return q60;
            break;
        case q60:
            if (input == 'M' || input == 'm') return q61;
            break;
        case q61:
            if (input == 'A' || input == 'a') return q62;
            break;
        case q62:
            if (input == 'N' || input == 'n') return ACCEPT;
            break;
        case q63:  // k == elas || antin
            if (input == 'E' || input == 'e') return q64;
            if (input == 'A' || input == 'a') return q75;
            break;
        case q64:  // Kelas
            if (input == 'L' || input == 'l') return q65;
            break;
        case q65:
            if (input == 'A' || input == 'a') return q66;
            break;
        case q66:
            if (input == 'S' || input == 's') return ACCEPT;
            break;
        case q67:  // rumah
            if (input == 'U' || input == 'u') return q68;
            break;
        case q68:
            if (input == 'M' || input == 'm') return q69;
            break;
        case q69:
            if (input == 'A' || input == 'a') return q70;
            break;
        case q70:
            if (input == 'H' || input == 'h') return ACCEPT;
            break;
        case q71:  // dapur
            if (input == 'A' || input == 'a') return q72;
            break;
        case q72:
            if (input == 'P' || input == 'p') return q73;
            break;
        case q73:
            if (input == 'U' || input == 'u') return q74;
            break;
        case q74:
            if (input == 'R' || input == 'r') return ACCEPT;
            break;
        case q75:  // kantin
            if (input == 'N' || input == 'n') return q76;
            break;
        case q76:
            if (input == 'T' || input == 't') return q77;
            break;
        case q77:
            if (input == 'I' || input == 'i') return q78;
            break;
        case q78:
            if (input == 'N' || input == 'n') return ACCEPT;
            break;
        default:
            return REJECT;
    }
    return REJECT;
};

class PushdownAutomaton {
public:
    bool processInput(string inputString) {
        stack<char> stk;
        StatePDA currentState = IS;

        for (char c : inputString) {
            switch (currentState) {
                case IS:
                    stk.push('#'); // Simbol awal stack
                    if (c == 'S') {
                        stk.push(c);
                        currentState = S_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case S_FOUND:
                    if (c == 'P') {
                        stk.pop();
                        currentState = P_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case P_FOUND:
                    if (c == 'O') {
                        currentState = O_FOUND;
                    } else if (c == 'K') {
                        currentState = K_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case O_FOUND:
                    if (c == 'K') {
                        currentState = K_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case K_FOUND:
                    currentState = INVALID;  // Tidak ada transisi valid dari K_FOUND
                    break;
                case INVALID:
                    break;  // Tetap di state INVALID
            }
        }

        // Validasi akhir: stack harus kosong setelah mengeluarkan simbol awal
        if ((currentState == P_FOUND || currentState == O_FOUND || currentState == K_FOUND)&& !stk.empty() && stk.top() == '#') {
            stk.pop();  // Keluarkan simbol awal
        }

        // Stack harus kosong sekarang jika string valid
        return (currentState == P_FOUND || currentState == O_FOUND || currentState == K_FOUND) && stk.empty();
    }
};

int main() {
    string struktur;
    string input;
    StateFA currentState;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);

    istringstream iss(input);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }
    if (words.size() <= 4){
        // periksa kata pertama
        if (words.size() >= 1){
            currentState = START;
            for (char ch : words[0]) {
                currentState = transitionSubjek(currentState, ch);
                if (currentState == REJECT) break;
            }
            if (currentState == ACCEPT) struktur = "S";
        }


        // periksa kata kedua
        if (words.size() >= 2){
            currentState = START;
            for (char ch : words[1]) {
                currentState = transitionPredikat(currentState, ch);
                if (currentState == REJECT) break;
            }
            if (currentState == ACCEPT) struktur += "P"; else struktur += "?"; //jika kata bukanlah predikat
        }

        // periksa kata ketiga
        if (words.size() >= 3){
            currentState = START;
            for (char ch : words[2]) {
                currentState = transitionObjek(currentState, ch);
                if (currentState == REJECT) break;
            }
            if (currentState == ACCEPT) struktur += "O"; else struktur += "?"; //jika kata bukanlah objek
        }

        // periksa kata keempat
        if (words.size() >= 4){
            currentState = START;
            for (char ch : words[3]) {
                currentState = transitionKeterangan(currentState, ch);
                if (currentState == REJECT) break;
            }
            if (currentState == ACCEPT) struktur += "K"; else struktur += "?"; //jika kata bukanlah keterangan
        }


        //cek menggunakan PDA
        PushdownAutomaton automaton;
        bool result = automaton.processInput(struktur);

        if (result) {
            cout << "'" << input << "' adalah string yang valid." << endl;
        } else {
            cout << "'" << input << "' bukan string yang valid." << endl;
        }

        cout << endl << "struktur kalimat : ";
        for (int i = 0; i < words.size(); i++){
            cout << struktur[i];
            if (i != words.size()-1) cout << " - ";
        }
    } else {
        cout << "'" << input << "' bukan string yang valid." << endl;
    }


    return 0;
};
