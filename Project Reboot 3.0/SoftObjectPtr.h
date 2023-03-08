#pragma once

#include "Object.h"

#include "PersistentObjectPtr.h"
#include "SoftObjectPath.h"

#include "reboot.h"

struct FSoftObjectPtr : public TPersistentObjectPtr<FSoftObjectPath>
{
public:
};

template<class T = UObject>
struct TSoftObjectPtr
{
public:
	FSoftObjectPtr SoftObjectPtr;

	T* Get()
	{
		if (SoftObjectPtr.ObjectID.AssetPathName.ComparisonIndex.Value <= 0)
			return nullptr;

		return FindObject<T>(SoftObjectPtr.ObjectID.AssetPathName.ToString());
	}
};