/****************************************************************************
* Copyright (C) 2018 Eric Mor
*
* This file is part of Spore ModAPI.
*
* Spore ModAPI is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#include <Spore\App\cCheatManager.h>
#include <Spore\ArgScript\LambdaParser.h>

namespace App
{
	auto_STATIC_METHOD_(ICheatManager, ICheatManager*, Get);

	auto_METHOD_VIRTUAL_(cCheatManager, cCheatManager, bool, Initialize);
	auto_METHOD_VIRTUAL_(cCheatManager, cCheatManager, bool, Dispose);
	auto_METHOD_VIRTUAL_VOID_(cCheatManager, cCheatManager, func14h);
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, AddCheat, PARAMS(const char* pString, ArgScript::ICommand* parser, bool bNotify), PARAMS(pString, parser, bNotify));
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, RemoveCheat, PARAMS(const char* pString), PARAMS(pString));
	auto_METHOD_VIRTUAL(cCheatManager, cCheatManager, bool, ProcessLine, PARAMS(const char* pString), PARAMS(pString));
	auto_METHOD_VIRTUAL_(cCheatManager, cCheatManager, int, func24h);
	auto_METHOD_VIRTUAL(cCheatManager, cCheatManager, ArgScript::ICommand*, GetCheat, PARAMS(const char* pKeyword), PARAMS(pKeyword));
	auto_METHOD_VIRTUAL(cCheatManager, cCheatManager, size_t, GetKeywords, PARAMS(const char* pPattern, vector<const char*> dst), PARAMS(pPattern, dst));
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, func30h, PARAMS(Object* arg_0), PARAMS(arg_0));
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, func34h, PARAMS(Object* arg_0), PARAMS(arg_0));
	auto_METHOD_VIRTUAL_(cCheatManager, cCheatManager, ArgScript::FormatParser*, GetArgScript);
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, func3Ch, PARAMS(int arg_0), PARAMS(arg_0));
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, func40h, PARAMS(int arg_0), PARAMS(arg_0));
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, func44h, PARAMS(int arg_0), PARAMS(arg_0));
	auto_METHOD_VIRTUAL_(cCheatManager, cCheatManager, bool, func48h);
	auto_METHOD_VIRTUAL_VOID(cCheatManager, cCheatManager, func4Ch, PARAMS(bool arg_0), PARAMS(arg_0));

	cCheatManager::cCheatManager()
		: mnRefCount(0)
		, mCheats()
		, mNotifyCheats()
		, mpArgScript(nullptr)
		, field_48()
		, field_68(true)
	{
	}

	int cCheatManager::AddRef()
	{
		return ++mnRefCount;
	}

	int cCheatManager::Release()
	{
		if (--mnRefCount == 0)
		{
			delete this;
		}
		return mnRefCount;
	}

	void ICheatManager::AddCheat(const char* pKeyword, ArgScript::ParseLine_t pParseLine, ArgScript::GetDescription_t pGetDescription, bool bNotify)
	{
		AddCheat(pKeyword, reinterpret_cast<ArgScript::ICommand*>(new ArgScript::LambdaParser(pParseLine, pGetDescription)), bNotify);
	}

}