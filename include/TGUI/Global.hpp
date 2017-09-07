/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2017 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TGUI_GLOBAL_HPP
#define TGUI_GLOBAL_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <TGUI/Config.hpp>
#include <TGUI/Exception.hpp>
#include <iostream>
#include <string>
#include <memory>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef TGUI_NO_CPP14
    namespace tgui
    {
        template<typename T, typename... Args>
        std::unique_ptr<T> make_unique(Args&&... args)
        {
            return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
        }
    }
#else
    using std::make_unique;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Namespace that contains all TGUI functions and classes
namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief While tab key usage is enabled (default), pressing tab will focus another widget
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void enableTabKeyUsage();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief When disabling the tab key usage, pressing tab will no longer focus another widget
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void disableTabKeyUsage();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets a new resource path
    ///
    /// This pathname is placed in front of every filename that is used to load a resource.
    ///
    /// @param path  New resource path
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void setResourcePath(const std::string& path);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Returns the resource path
    ///
    /// This pathname is placed in front of every filename that is used to load a resource.
    ///
    /// @return The current resource path
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API const std::string& getResourcePath();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Checks if two floats are equal, with regard to a small epsilon margin.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool compareFloats(float x, float y);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Checks if a character is a whitespace character.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool isWhitespace(char character);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Converts a string to an integer. Acts like std::stoi which isn't supported in MinGW TDM.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API int stoi(const std::string& value);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Converts a string to a float. Acts like std::stof which isn't supported in MinGW TDM.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API float stof(const std::string& value);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Extracts a bool from a string value.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool extractBoolFromString(const std::string& property, const std::string& value);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Moves the iterator forward until no more whitespace is found
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool removeWhitespace(const std::string& line, std::string::const_iterator& c);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Converts a string to lowercase.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API std::string toLower(std::string str);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @internal
    // Trims the whitespace from a string.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API std::string trim(std::string str);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_GLOBAL_HPP

