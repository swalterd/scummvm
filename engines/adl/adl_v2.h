/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ADL_ADL_V2_H
#define ADL_ADL_V2_H

#include "adl/adl.h"

// Note: this version of ADL redraws only when necessary, but
// this is not currently implemented.

namespace Common {
class RandomSource;
}

namespace Adl {

class AdlEngine_v2 : public AdlEngine {
public:
	virtual ~AdlEngine_v2();

protected:
	AdlEngine_v2(OSystem *syst, const AdlGameDescription *gd);

	// AdlEngine
	virtual void setupOpcodeTables();
	virtual void initState();
	byte roomArg(byte room) const;
	void advanceClock();
	virtual void printString(const Common::String &str);
	virtual Common::String loadMessage(uint idx) const;
	void drawItems();
	void drawItem(Item &item, const Common::Point &pos);
	void loadRoom(byte roomNr);
	virtual void showRoom();
	void takeItem(byte noun);

	virtual DataBlockPtr readDataBlockPtr(Common::ReadStream &f) const;

	void checkTextOverflow(char c);

	int o2_isFirstTime(ScriptEnv &e);
	int o2_isRandomGT(ScriptEnv &e);
	int o2_isNounNotInRoom(ScriptEnv &e);
	int o2_isCarryingSomething(ScriptEnv &e);

	int o2_moveItem(ScriptEnv &e);
	int o2_moveAllItems(ScriptEnv &e);
	int o2_save(ScriptEnv &e);
	int o2_restore(ScriptEnv &e);
	int o2_placeItem(ScriptEnv &e);
	int o2_tellTime(ScriptEnv &e);
	int o2_setRoomFromVar(ScriptEnv &e);
	int o2_initDisk(ScriptEnv &e);

	struct {
		Common::String time;
		Common::String saveInsert, saveReplace;
		Common::String restoreInsert, restoreReplace;
	} _strings_v2;

	uint _linesPrinted;
	DiskImage *_disk;
	Common::Array<DataBlockPtr> _itemPics;
	bool _itemRemoved;
	byte _roomOnScreen, _picOnScreen, _itemsOnScreen;

private:
	int askForSlot(const Common::String &question);

	Common::RandomSource *_random;
};

} // End of namespace Adl

#endif
