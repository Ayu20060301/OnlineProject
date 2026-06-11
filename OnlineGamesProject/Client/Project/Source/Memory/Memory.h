#pragma once

#include<memory>

//型エイリアス
template<typename T>
using UniquePtr = std::unique_ptr<T>;
template<typename T>
using SharedPtr  = std::shared_ptr<T>;
template<typename T>
using WeakPtr   = std::weak_ptr<T>;

template<typename T,typename... Args>
UniquePtr<T> MakeUnique(Args&&... Args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T, typename... Args>
SharedPtr<T> MakeShared(Args&&... Args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}
