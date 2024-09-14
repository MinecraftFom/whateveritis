#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Function to get command type
int get_ret_type(const string &in) {
    if (in == "quit") {
        return 0;
    } else if (in == "setpassword") {
        return 1;
    } else if (in == "setusername") {
        return 2;
    } else {
        return -1145;
    }
}

int main() {
    system("color 0A");
    // Read inputs from files
    string fng, fpg, fog;
    ifstream fn(".username");
    getline(fn, fng);
    fn.close();
    ifstream fp(".password");
    getline(fp, fpg);
    fp.close();
    ifstream fo(".open_statues");
    getline(fo, fog);
    fo.close();

    cout << "One In All" << endl;
    if (fog == "true") {
        cout << "Hello, User " << fng << " !" << endl;
        cout << "REMEMBER TO ENTER SPACE BEFORE ENTERING A COMMAND!!!" << endl;
        while (true) {
            string gpsfu;
            cout << "Enter Password > ";
            cin >> gpsfu;
            if (gpsfu == fpg) {
                break;
            } else {
                cout << "Incorrect password. Try again." << endl;
            }
        }
    } else {
        ofstream fop(".password");
        ofstream fop2(".open_statues");
        fop << "12345678";
        fop2 << "true";
        fop.close();
        cout << "Hello, User Default Admin! Use '/setn' to Set User Name. \nYour Initial Password is 12345678. Use '/setp' to Set Password" << endl;

    }

    // Read command input
    while (true) {
        string read_in;
        cout << "$ ";
        getline(cin, read_in);

        // Ensure the command starts with '/'
        if (!read_in.empty() && read_in[0] == '/') {
            string command = read_in.substr(1); // Extract command without '/'
            size_t space_pos = command.find(' '); // Find the first space
            string cmd_type = (space_pos == string::npos) ? command : command.substr(0, space_pos); // Extract command type
            string cmd_param = (space_pos == string::npos) ? "" : command.substr(space_pos + 1); // Extract parameter

            int command_type = get_ret_type(cmd_type);

            switch (command_type) {
                case 0:
                    exit(-1145);
                case 1: {
                    ofstream spd(".password");
                    spd << cmd_param; // Set new password
                    spd.close();
                    cout << "Have set password to " << cmd_param << endl;
                    break;
                }
                case 2: {
                    ofstream sun(".username");
                    sun << cmd_param; // Set new username
                    sun.close();
                    cout << "Have set username to " << cmd_param << endl;
                    break;
                }
                default:
                    cout << read_in << endl;
            }
        } else {
            cout << read_in << endl;
        }
    }

    return 0;
}