#include "FIleSystemNode.h"

FileSystemNode::FileSystemNode(FileSystemNode&& node) noexcept
{
    m_path = std::move(node.m_path);
    setSize();
}

const std::filesystem::path& FileSystemNode::get_path() const
{
    return m_path;
}

inline const std::filesystem::file_time_type FileSystemNode::get_last_write_time()
{
    return std::filesystem::last_write_time(m_path);
}

inline bool FileSystemNode::isFile() const
{
    return std::filesystem::is_regular_file(m_path);
}

inline bool FileSystemNode::isDirectory() const
{
    return std::filesystem::is_directory(m_path);
}

inline bool FileSystemNode::isVisible(const std::filesystem::directory_entry& entry)
{
    QFileInfo file_info(entry.path());
    return !file_info.isHidden();
}

const size_t FileSystemNode::getSize()
{
    return m_size;
}

