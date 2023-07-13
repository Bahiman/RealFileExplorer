#pragma once
#include<filesystem>
#include<qfileinfo.h>
class FileSystemNode
{
protected:
	std::filesystem::path m_path;
	size_t m_size;
	virtual void setSize() = 0;
public:
	FileSystemNode() = delete;
	explicit FileSystemNode(FileSystemNode&& node) noexcept;
	template<typename T>
	FileSystemNode(T&& arg);
	virtual ~FileSystemNode() = default;
	const std::filesystem::path& get_path() const;
	inline const std::filesystem::file_time_type get_last_write_time();
	inline bool isFile() const;
	inline bool isDirectory() const;
	static inline bool isVisible(const std::filesystem::directory_entry& entry);
	const size_t getSize();
};

template<typename T>
inline FileSystemNode::FileSystemNode(T&& arg)
{
	m_path = std::forward<T>(arg);
	setSize();
}
