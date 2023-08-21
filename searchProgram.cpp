#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cstdlib>

int main() {

    int result = system("python script.py");
    if (result == 0){
        std::string filename = "output.html"; // Replace with the HTML file's path
        std::ifstream inputFile(filename);
    
        if (!inputFile.is_open()) {
           std::cerr << "Error opening file." << std::endl;
            return 1;
        }

        std::string htmlContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        inputFile.close();

        std::regex linkPattern("<a\\s+[^>]*href=([\"'])(.*?)\\1");
        std::smatch match;

        std::cout << "Links found in the HTML file:" << std::endl;
        std::string::const_iterator searchStart(htmlContent.cbegin());

        while (std::regex_search(searchStart, htmlContent.cend(), match, linkPattern)) {
            std::cout << match[2] << std::endl;
            searchStart = match.suffix().first;
         }
    }else{
        std::cout << "Python Script Failed";
    }
    return 0;
}