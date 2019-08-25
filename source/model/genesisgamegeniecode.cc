/*
 * Game Genie Encoder/Decoder
 * Copyright (C) 2004-2005 emuWorks
 * http://games.technoplaza.net/
 *
 * This file is part of Game Genie Encoder/Decoder.
 *
 * Game Genie Encoder/Decoder is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Game Genie Encoder/Decoder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Game Genie Encoder/Decoder; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
// $Id: genesisgamegeniecode.cc,v 1.4 2005/07/30 02:36:45 technoplaza Exp $

#include "genesisgamegeniecode.hh"
#include "../exceptions/invalidgamegeniecode.hh"

using namespace emuWorks;

const char GenesisGameGenieCode::ALPHABET[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'J', 'K', 'L', 'M', 'N', 'P', 'R', 'S',
    'T', 'V', 'W', 'X', 'Y', 'Z', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9'
};

GenesisGameGenieCode GenesisGameGenieCode::create(QString &code) {
    if (isValidCode(code)) {
        return GenesisGameGenieCode(code);
    }
    
    throw InvalidGameGenieCodeException();
}

bool GenesisGameGenieCode::isValidCode(QString &code) {
    GenesisGameGenieCode temp(code);
    
    const char *alphabet = temp.getAlphabet();
    int count = temp.getAlphabetCount();
    
    QString upper = code.toUpper();
    int length = upper.length();
    
    if (length != 9) {
        return false;
    }
    
    if (code[4] != '-') {
        return false;
    }
    
    for (int i = 0; i < length; i++) {
        if (i == 4) {
            continue;
        }
        
        bool found = false;
        QChar ch = code[i];
        char letter = ch.toAscii();
        
        for (int j = 0; j < count; j++) {
            if (letter == alphabet[j]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            return false;
        }
    }
    
    return true;
}

const char *GenesisGameGenieCode::getAlphabet() {
    return ALPHABET;
}
