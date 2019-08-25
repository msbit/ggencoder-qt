/*
 * Game Genie Encoder/Decoder
 * Copyright (C) 2004-2006 emuWorks
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
 
// $Id: encoder.hh,v 1.4 2006/08/18 22:17:24 technoplaza Exp $

#ifndef _ENCODER_HH
#define _ENCODER_HH

namespace emuWorks {
    class GBGGGameGenieCode;
    class GBGGRawCode;
    class GenesisGameGenieCode;
    class GenesisRawCode;
    class NESGameGenieCode;
    class NESRawCode;
    class SNESGameGenieCode;
    class SNESRawCode;
    
    /**
     * A class to encode raw/PAR codes into Game Genie codes.
     */
    class Encoder {
    private:
        /**
         * Constructor for an Encoder. Private to prevent instantiation.
         */
        Encoder();
        
    public:
        /**
         * Encodes a GBGGRawCode into a GameGenieCode.
         *
         * @param code The GBGGRawCode.
         *
         * @return The encoded GameGenieCode.
         */
        static GBGGGameGenieCode encode(const GBGGRawCode &code);
        
        /**
         * Encodes a GenesisRawCode into a GameGenieCode.
         *
         * @param code The GenesisRawCode.
         *
         * @return The encoded GameGenieCode.
         */
        static GenesisGameGenieCode encode(const GenesisRawCode &code);
        
        /**
         * Encodes an NESRawCode into a GameGenieCode.
         *
         * @param code The NESRawCode.
         *
         * @return The encoded GameGenieCode.
         */
        static NESGameGenieCode encode(const NESRawCode &code);

        /**
         * Encodes an SNESRawCode into a GameGenieCode.
         *
         * @param code The SNESRawCode.
         *
         * @return The encoded GameGenieCode.
         */
        static SNESGameGenieCode encode(const SNESRawCode &code);
    };
    
    inline Encoder::Encoder() {}
}

#endif

