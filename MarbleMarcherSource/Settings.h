/* This file is part of the Marble Marcher (https://github.com/HackerPoet/MarbleMarcher).
* Copyright(C) 2018 CodeParade
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once
#include <fstream>

class Settings {
public:
  Settings() :
    mute(false),
    mouse_sensitivity(0) {
  }

  void Load(const std::string& fname) {
    std::ifstream fin(fname, std::ios::binary);
    if (!fin) { return; }
    fin.read((char*)this, sizeof(this));
  }
  void Save(const std::string& fname) {
    std::ofstream fout(fname, std::ios::binary);
    if (!fout) { return; }
    fout.write((char*)this, sizeof(this));
  }

  bool   mute;
  int    mouse_sensitivity;
};