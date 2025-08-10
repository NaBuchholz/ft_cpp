#include <iostream>
#include <fstream>
#include <string>

std::string	replaceAllOccurrences(std::string str, const std::string& s1, const std::string& s2)
{
	std::string result;
    size_t pos;
    size_t found;
    
    pos = 0;
    found = str.find(s1, pos);
    while (found != std::string::npos)
    {
        result += str.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
        found = str.find(s1, pos);
    }
    result += str.substr(pos);
    return (result);
}

bool	openFiles(const std::string& filename, std::ifstream& inputFile, std::ofstream& outputFile)
{
	std::string outputFilename;
    
    inputFile.open(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: cannot open input file " << filename << std::endl;
        return (false);
    }
    
    outputFilename = filename + ".replace";
    outputFile.open(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: cannot create output file " << outputFilename << std::endl;
        inputFile.close();
        return (false);
    }
    
    return (true);
}

void	processFile(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& s1, const std::string& s2)
{
    std::string line;
    std::string processedLine;
    
    while (std::getline(inputFile, line))
    {
        processedLine = replaceAllOccurrences(line, s1, s2);
        outputFile << processedLine << std::endl;
    }
}

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (!openFiles(argv[1], inputFile, outputFile))
		return 1;
	processFile(inputFile, outputFile, argv[2], argv[3]);
	inputFile.close();
	outputFile.close();
	return 0;
}