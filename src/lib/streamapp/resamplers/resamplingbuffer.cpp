/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 4.                                               *
 *                                                                            *
 * APEX 4 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 4 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 4.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/

#include "resamplingbuffer.h"
#include "resamplers/resampler.h"

using namespace streamapp;

ResamplingBuffer::ResamplingBuffer(IResampler &a_Resampler,
                                   const unsigned ac_nOutputSize)
    : BasicBuffer(a_Resampler.mf_nGetNumChannels(),
                  a_Resampler.mf_nGetOutputBufferSize(),
                  ac_nOutputSize / a_Resampler.mf_nGetOutputBufferSize()),
      m_Resampler(a_Resampler)
{
}

ResamplingBuffer::~ResamplingBuffer()
{
}

const Stream &ResamplingBuffer::mf_DoProcessing(const Stream &ac_StrToProc)
{
    const Stream &res = m_Resampler.mf_DownSample(ac_StrToProc);
    BasicBuffer::mf_DoProcessing(res);
    return ac_StrToProc;
}
