#include "Directory.h"


void Directory::setSize()
{
    size_t totalSize = 0;
    namespace fs = std::filesystem;
    for (const auto& entry : fs::recursive_directory_iterator(m_path)) {
        if (fs::is_regular_file(entry)) {
            totalSize += fs::file_size(entry);
        }
    }
}

Directory::Directory(FileSystemNode&& node) noexcept : Directory(std::move(node))
{
    m_previous_directory = getPreviousDirectory(m_path);
}

std::filesystem::path Directory::getPreviousDirectory(const std::filesystem::path& path)
{
    return path.parent_path();
}
