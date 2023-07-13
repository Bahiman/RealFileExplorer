#include "FileOperations.h"

std::vector<std::unique_ptr<FileSystemNode>> FileOperations::getEverythingInDirectory(const std::filesystem::path& path)
{
    std::vector<std::unique_ptr<FileSystemNode>> everything;
    for (auto& entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
			everything.emplace_back(std::make_unique<Directory>(entry.path()));
		}
        else if (entry.is_regular_file())
        {
			everything.emplace_back(std::make_unique<File>(entry.path()));
		}
	}

    return everything;
}

std::vector<std::unique_ptr<Directory>> FileOperations::getDirectoriesInDirectory(const std::filesystem::path& path)
{
    std::vector<std::unique_ptr<Directory>> everything;
    for (auto& entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            everything.emplace_back(std::make_unique<Directory>(entry.path()));
        }
    }      

    return everything;
}

std::vector<std::unique_ptr<File>> FileOperations::getFilesInDirectory(const std::filesystem::path& path)
{
     std::vector<std::unique_ptr<File>> everything;
     for (auto& entry : std::filesystem::directory_iterator(path))
     {
         if (entry.is_regular_file())
         {
			 everything.emplace_back(std::make_unique<File>(entry.path()));
		 }
	 }
}


