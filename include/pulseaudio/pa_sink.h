/* -*- c++ -*- */
/*
 * Copyright 2013 Phil Frost.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_PULSEAUDIO_PA_SINK_H
#define INCLUDED_PULSEAUDIO_PA_SINK_H

#include <pulseaudio/api.h>
#include <gr_sync_block.h>

namespace gr {
  namespace pulseaudio {

    /*!
     * \brief <+description of block+>
     * \ingroup pulseaudio
     *
     */
    class PULSEAUDIO_API pa_sink : virtual public gr_sync_block
    {
    public:
       typedef boost::shared_ptr<pa_sink> sptr;

       /*!
        * \brief Return a shared_ptr to a new instance of pulseaudio::pa_sink.
        *
        * To avoid accidental use of raw pointers, pulseaudio::pa_sink's
        * constructor is in a private implementation
        * class. pulseaudio::pa_sink::make is the public interface for
        * creating new instances.
        */
       static sptr make(
          int samp_rate,
          int nchannels,
          const char *application_name,
          const char *stream_name,
          const char *channel_map);
    };

  } // namespace pulseaudio
} // namespace gr

#endif /* INCLUDED_PULSEAUDIO_PA_SINK_H */

