#pragma once
#include"FIleSystemNode.h"

class Directory : public FileSystemNode
{
private:
	std::filesystem::path m_previous_directory;
	void setSize() override;
public:
	Directory() = delete;
	template<typename T>
	Directory(T&& path);
	explicit Directory(FileSystemNode&& node) noexcept;
	static std::filesystem::path getPreviousDirectory(const std::filesystem::path& path);
	virtual ~Directory() = default;
};

template<typename T>
inline Directory::Directory(T&& path)
{
	m_path = std::forward<T>(path);
}
