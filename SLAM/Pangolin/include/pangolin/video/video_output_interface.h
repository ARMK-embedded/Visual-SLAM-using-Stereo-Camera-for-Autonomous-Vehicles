/* This file is part of the Pangolin Project.
 * http://github.com/stevenlovegrove/Pangolin
 *
 * Copyright (c) 2011-2013 Steven Lovegrove
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <vector>
#include <pangolin/platform.h>
#include <pangolin/video/stream_info.h>
#include <pangolin/utils/picojson.h>

namespace pangolin {

//! Interface to video recording destinations
struct PANGOLIN_EXPORT VideoOutputInterface
{
    virtual ~VideoOutputInterface() {}

    //! Get format and dimensions of all video streams
    virtual const std::vector<StreamInfo>& Streams() const = 0;

    virtual void SetStreams(const std::vector<StreamInfo>& streams, const std::string& uri ="", const json::value& properties = json::value() ) = 0;

    virtual int WriteStreams(const unsigned char* data, const json::value& frame_properties = json::value() ) = 0;

    virtual bool IsPipe() const = 0;
};

}
