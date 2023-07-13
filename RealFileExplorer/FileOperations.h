#pragma once
#include<filesystem>
#include"File.h"
#include"Directory.h"

namespace FileOperations
{
	std::vector<std::unique_ptr<FileSystemNode>> getEverythingInDirectory(const std::filesystem::path& path);
	std::vector<std::unique_ptr<Directory>> getDirectoriesInDirectory(const std::filesystem::path& path);
	std::vector<std::unique_ptr<File>> getFilesInDirectory(const std::filesystem::path& path);

};