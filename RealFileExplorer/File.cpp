#include "File.h"

void File::setSize()
{
    m_size = std::filesystem::file_size(m_path);
}

inline std::string File::getExtension()
{
    return m_path.extension().string();
}

inline std::string File::getFileName()
{
    return m_path.filename().stem().string();
}

inline std::string File::getFileNameWithExtension()
{
    return m_path.filename().string();
}


File::File(FileSystemNode&& node) : FileSystemNode(std::move(node))
{

}

template<typename T>
inline File::File(T&& arg)
{
    if (!m_path.has_extension())
        throw std::invalid_argument("The path must have an extension.");
}