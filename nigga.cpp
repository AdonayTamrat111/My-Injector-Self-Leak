#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <intrin.h> // For __rdtsc() function

using namespace web;

// Function to detect if debugger is present
bool isDebuggerPresent() {
    return IsDebuggerPresent() || CheckRemoteDebuggerPresent(GetCurrentProcess(), nullptr);
}

// Function to calculate checksum of a memory region
DWORD calculateChecksum(const BYTE* data, size_t size) {
    DWORD checksum = 0;
    for (size_t i = 0; i < size; ++i) {
        checksum += data[i];
    }
    return checksum;
}

// Function to send webhook to Discord
void sendWebhook(const std::string& webhookURL, const std::string& message) {
    try {
        http_client client(webhookURL);

        json::value payload;
        payload[U("content")] = json::value::string(utility::conversions::to_utf16string(message));

        http_response response = client.request(methods::POST, U(""), payload.to_string()).get();
        if (response.status_code() == status_codes::OK) {
            std::cout << "Webhook sent successfully\n";
        }
        else {
            std::cerr << "Failed to send webhook. Status code: " << response.status_code() << "\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << "\n";
    }
}

// Function to get computer name and IP address
std::string getComputerInfo() {
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    hostent* host = gethostbyname(hostname);
    if (host == nullptr) {
        return "Unknown (Failed to retrieve IP address)";
    }

    char* ip = inet_ntoa(*reinterpret_cast<struct in_addr*>(host->h_addr_list[0]));
    return std::string(hostname) + " (" + std::string(ip) + ")";
}

// Function to delete the executable file
void deleteExecutable() {
    std::string executablePath = __argv[0];
    std::remove(executablePath.c_str());
}

int main() {
    // Setting up
    std::string webhookURL = "https://discordapp.com/api/webhooks/1262883742930833509/yjsP0hY-vDsw_iwxhNtGuf3Hm8YV-e-C68HxyoMuM89YVoXCqU3yxqT4a7oYm_ClBQD6"; // Replace with your Discord webhook URL

    // Check if debugger is present
    if (isDebuggerPresent()) {
        std::cout << "Debugger detected. Exiting...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 1;
    }

    // Calculate checksum of critical code section
    const BYTE* codeSectionStart = reinterpret_cast<const BYTE*>(main);
    const BYTE* codeSectionEnd = codeSectionStart + 1000; // Adjust the size as needed
    DWORD originalChecksum = calculateChecksum(codeSectionStart, codeSectionEnd - codeSectionStart);

    // Continuously check if the code has been tampered with
    while (true) {
        DWORD currentChecksum = calculateChecksum(codeSectionStart, codeSectionEnd - codeSectionStart);
        if (currentChecksum != originalChecksum) {
            std::cout << "Code has been tampered with. Deleting executable and sending webhook...\n";
            sendWebhook(webhookURL, "Attempted cracking detected!\n"
                "Computer: " + getComputerInfo() + "\n"
                "IP Address: [REPLACE_WITH_IP_ADDRESS]\n"); // Replace [REPLACE_WITH_IP_ADDRESS] with actual IP address

            deleteExecutable(); // Delete the executable file
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(10)); // Check every 10 seconds
    }

    return 0;
}
