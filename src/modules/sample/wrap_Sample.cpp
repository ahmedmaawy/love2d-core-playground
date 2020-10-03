/**
 * Copyright (c) 2006-2019 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 **/

// LOVE
#include "Sample.h"
#include "wrap_Sample.h"
#include "common/config.h"

#include <iostream>

namespace love
{
namespace sample
{

#define instance() (Module::getInstance<Sample>(Module::M_SAMPLE))

int w_doSum(lua_State *L) {
	int num1 = (int) luaL_optinteger(L, 1, 0);
	int num2 = (int) luaL_optinteger(L, 2, 0);
	lua_pushnumber(L, num1 + num2);
	return 1;
}

// List of functions to wrap.
static const luaL_Reg functions[] =
{
	{ "doSum", w_doSum },
	{ 0, 0 }
};

extern "C" int luaopen_love_sample(lua_State *L)
{
	Sample *instance = instance();

	if (instance == nullptr)
	{
		std::cout << "Sample Module was null\n";
		luax_catchexcept(L, [&](){ instance = new love::sample::Sample(); });
	}
	else
	{
		std::cout << "Sample Module was not null\n";
		instance->retain();
	}

	std::cout << "Wrapping sample module\n";

	WrappedModule w;
	w.module = instance;
	w.name = "sample";
	w.type = &Module::type;
	w.functions = functions;
	w.types = 0;

	std::cout << "Registering 'sample' onto Lua\n";

	return luax_register_module(L, w);
}

} // sample
} // love
