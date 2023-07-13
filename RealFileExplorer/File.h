#pragma once
#include"FIleSystemNode.h"

class File : public FileSystemNode
{
private:
	void setSize() override;
public:
	inline std::string getExtension();
	inline std::string getFileName();
	inline std::string getFileNameWithExtension();
	File() = delete;
	template<typename T>
	File(T&& path);
	explicit File(FileSystemNode&& node);
};
