#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
	// BAT file: Checks if "ExampleFolder" exists on the Desktop and creates it if not.
	const char* batContent =
		"@echo off\n"
		"set folder=%USERPROFILE%\\Desktop\\ExampleFolder\n"
		"if exist \"%folder%\\\" (\n"
		"    echo Folder exists.\n"
		") else (\n"
		"    mkdir \"%folder%\"\n"
		"    echo Folder created.\n"
		")\n"
		"pause\n";

	// PowerShell script: Performs the same check and action.
	const char* psContent =
		"$folder = \"$env:USERPROFILE\\Desktop\\ExampleFolder\"\n"
		"if (Test-Path $folder) {\n"
		"    Write-Host \"Folder exists.\"\n"
		"} else {\n"
		"    New-Item -ItemType Directory -Path $folder\n"
		"    Write-Host \"Folder created.\"\n"
		"}\n";

	// Write the BAT file to disk.
	std::ofstream batFile("check_folder.bat");
	if (batFile.is_open()) {
		batFile << batContent;
		batFile.close();
		std::cout << "Batch file 'check_folder.bat' created successfully." << std::endl;
	} else {
		std::cerr << "Error creating the batch file." << std::endl;
		return (1);
	}

	// Write the PowerShell script to disk.
	std::ofstream psFile("check_folder.ps1");
	if (psFile.is_open()) {
		psFile << psContent;
		psFile.close();
		std::cout << "PowerShell script 'check_folder.ps1' created successfully." << std::endl;
	} else {
		std::cerr << "Error creating the PowerShell script." << std::endl;
		return (1);
	}

	// Execute the batch file.
	std::cout << "Executing batch file..." << std::endl;
	int batResult = system("check_folder.bat");
	std::cout << "Batch file returned: " << batResult << std::endl;

	// Execute the PowerShell script.
	// The -ExecutionPolicy Bypass option is used to avoid potential script policy restrictions.
	std::cout << "Executing PowerShell script..." << std::endl;
	int psResult = system("powershell -ExecutionPolicy Bypass -File check_folder.ps1");
	std::cout << "PowerShell script returned: " << psResult << std::endl;

	return (0);
}
