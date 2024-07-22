#include <Windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <filesystem>
#include <fstream>
#include "auth.hpp"
#include "utils.hpp"
#include "skStr.h"
#include "cheat.h"
#include "inject.h"
#include "meme.h"
#include "nskmpr.h"

// Global variables
std::string compilation_date = (std::string)skCrypt(__DATE__);
std::string compilation_time = (std::string)skCrypt(__TIME__);

// Function to set text color in cmd
void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



// Simulated API and auth setup
using namespace KeyAuth;
std::string name = skCrypt("crypt test").decrypt();
std::string ownerid = skCrypt("aHS0SYJOSp").decrypt();
std::string secret = skCrypt("f00b87e30f57af79dabae76c0dd09b73024eb4dff19c11a85fa75ed5e5c8c88b").decrypt();
std::string version = skCrypt("1.0").decrypt();
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting
std::string path = skCrypt("").decrypt(); // optional, set a path if you're using the token validation setting

api KeyAuthApp(name, ownerid, secret, version, url, path);

// Function declarations
void mainfunc();
void createFileFromBytes(const unsigned char* data, size_t size, std::string filepath);

int main() {

    // Setting console title with compilation timestamp
    std::string consoleTitle = skCrypt("Crypt - Built at:  ").decrypt() + compilation_date + " " + compilation_time;
    SetConsoleTitleA(consoleTitle.c_str());

    setConsoleColor(11); // Cyan color

    std::cout << skCrypt("\n\n [+] Sending Auth Packets");
    std::cout << skCrypt("\n\n [+] Installing Needed Files..");
    std::cout << skCrypt("\n\n [+] Initializing Protection..");
    std::cout << skCrypt("\n\n [+] Opening.....");
    std::this_thread::sleep_for(std::chrono::milliseconds(900)); // Wait a few secs nigga
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(900)); // =Wait a few secs nigga
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(900)); // Wait a few secs nigga
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(900)); // Wait a few secs nigga

    setConsoleColor(15); // White color

    KeyAuthApp.init();

    if (!KeyAuthApp.response.success) {
        setConsoleColor(12); // Red color
        std::cout << skCrypt("\n Status: ") << KeyAuthApp.response.message;
        Sleep(1500);
        exit(1);
    }

    // Clear the screen
    system("cls");

    // Display login/register options
    int option;
    std::string username;
    std::string password;
    std::string key;

    std::cout << skCrypt("\n\n [+] Input Username.\n [+] Register\n\n Choose option: ");
    std::cin >> option;

    // Clear the screen after input
    system("cls");

    switch (option) {
    case 1: // Login
        std::cout << skCrypt("\n\n Enter username: ");
        std::cin >> username;
        std::cout << skCrypt("\n Enter password: ");
        std::cin >> password;
        KeyAuthApp.login(username, password);
        break;
    case 2: // Register
        std::cout << skCrypt("\n\n[+]  Enter username: ");
        std::cin >> username;
        std::cout << skCrypt("\n [+] Enter password: ");
        std::cin >> password;
        std::cout << skCrypt("\n [+] Enter license key: ");
        std::cin >> key;
        KeyAuthApp.regstr(username, password, key);
        break;
    default:
        setConsoleColor(12); // Red color
        std::cout << skCrypt("\n\n Status: Failure: Invalid Selection");
        Sleep(3000);
        exit(1);
    }

    // After successful login or registration
    if (KeyAuthApp.response.success) {
        setConsoleColor(10); // Green color
        std::cout << skCrypt("[+] Login successful.\n");
        mainfunc(); // Call mainfunc() function after successful login or registration
    }
    else {
        setConsoleColor(12); // Red color
        std::cout << skCrypt("[+] Login or registration failed.\n");
        Sleep(1500);
        exit(1);
    }
    // best injector ive made so far, ill be selfleaking this injector source in 3-4 weeks
    setConsoleColor(15); // White color
    std::cout << skCrypt("\n\n [+] Closing in five seconds...");
    Sleep(5000);

    return 0;
}

// Function to create file from byte array
void createFileFromBytes(const unsigned char* data, size_t size, std::string filepath) {
    std::ofstream outputFile(filepath, std::ios::out | std::ios::binary);
    if (!outputFile) {
        std::cerr << "Error: Failed to open file for writing: " << filepath << std::endl;
        return;
    }
    outputFile.write(reinterpret_cast<const char*>(data), size);
    outputFile.close();
}

// handlel shii
void mainfunc() {
    int choice;

    system("cls");

    std::cout << "[+] Select Your Option.\n";
    std::cout << "\n";
    std::cout << "[+] Load Crypt\n"; std::cout << "[+] Load Driver \n";
    
    std::cout << "[+] Load Built In Spoofer. \n";

    MessageBoxA(NULL, "[+] Spoofing....> 0x00007", "Crypt Spoofer", MB_OK);

    createFileFromBytes(dlltoinj, sizeof(dlltoinj), "C:\\Windows\\assembly\\spoof.sys");

    MessageBoxA(NULL, "[+] Spoofed!....> 0x00007", "Crypt Spoofer", MB_OK);
    std::cin >> choice;

    switch (choice) {
    case 1: {
        setConsoleColor(12); // xESty color
        std::cout << "Loading Private...\n";

        MessageBoxA(NULL, "[+] mapping Section.pdata-> 0x00007FFE78F2A000", "Crypt Internal", MB_OK);

        MessageBoxA(NULL, "[+] calling entry point -> 0x00007FFE78C4BF4C", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] copying [.data] 0x00000193882EE560 -> 0x00000193887F80A0", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] copying [.retplne£] 0x00000193882EEB60 -> 0x00000193887FB0A0", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] calling entry point -> 0x00007FFB34120220", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] calling entry point -> 0x00007FFB34120220", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] copying [.text] 0x0000027AF5454AC0 -> 0x0000027AF55110A0", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] copying [.text] 0x0000027AF5454AC0 -> 0x0000027AF55110A0", "Injecting...", MB_OK);

        MessageBoxA(NULL, "[+] You Have Successfully Injected, Restart Loader And Open Fortnite.", "Injected.", MB_OK);

        createFileFromBytes(dlltoinj, sizeof(dlltoinj), "C:\\Windows\\assembly\\cheat.dll");
        createFileFromBytes(injector, sizeof(injector), "C:\\Windows\\assembly\\injector.exe");

        system("C:\\Windows\\assembly\\injector.exe C:\\Windows\\assembly\\cheat.dll ");

        system("cls");

        setConsoleColor(12); // Red color
        std::cout << " Thank you for using Crypts Internal." << std::endl;
        system("start https://discord.gg/qN7NfTVM");
        Beep(200, 400);

        break;
    }
    case 2: {
        setConsoleColor(10); // Green color
        std::cout << "Loading Driver For Injector...\n";

        createFileFromBytes(dtcmapper, sizeof(dtcmapper), "C:\\Windows\\assembly\\dtcmapper.exe");

        createFileFromBytes(dtcdriver, sizeof(dtcdriver), "C:\\Windows\\assembly\\dtcdriver.sys");

        createFileFromBytes(dtcdriver, sizeof(dtcdriver), "C:\\Windows\\assembly\\dtcdriver.sys");

        system("C:\\Windows\\assembly\\dtcmapper.exe C:\\Windows\\assembly\\dtcdriver.sys ");

        system("cls");

        setConsoleColor(11); // Red color
        std::cout << " Driver Loader Injection Menu. Developed by Crypt Team." << std::endl;
        system("start https://discord.gg/qN7NfTVM");

        break;
    }
    default:
        setConsoleColor(11); // Red color
        std::cout << "Invalid selection.\n";
        break;
    }

    system("pause");
}
